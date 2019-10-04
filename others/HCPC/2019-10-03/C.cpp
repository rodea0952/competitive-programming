#pragma GCC optimize("O3")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool visited[50][50][50][50];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(1){
        int w, h; cin>>w>>h;
        if(w == 0) break;

        cin.ignore();
        vector<string> s(h), t(h);
        for(int i=0; i<h; i++){
            string st;
            getline(cin, st);
        
            string S = st.substr(0, w);
            string T = st.substr(w + 1, w);
            reverse(T.begin(), T.end());

            s[i] = S, t[i] = T;
        }

        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
                for(int k=0; k<50; k++){
                    for(int l=0; l<50; l++) visited[i][j][k][l] = false;
                }
            }
        }

        P sl, sr;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(s[i][j] == 'L'){
                    sl = P(i, j);
                    s[i][j] = '.';
                }
                if(t[i][j] == 'R'){
                    sr = P(i, j);
                    t[i][j] = '.';
                }
            }
        }

        // visited[ly][lx][ry][rx]
        visited[sl.first][sl.second][sr.first][sr.second] = true;
        queue<T> que;
        que.emplace(sl.first, sl.second, sr.first, sr.second);

        bool can_goal = false;
        while(que.size()){
            int cly, clx, cry, crx;
            tie(cly, clx, cry, crx) = que.front(); que.pop();

            if(s[cly][clx] == '%' && t[cry][crx] == '%'){
                cout << "Yes" << endl;
                can_goal = true;
                break;
            }

            for(int i=0; i<4; i++){
                int nly = cly + dy[i], nlx = clx + dx[i], nry = cry + dy[i], nrx = crx + dx[i];

                bool L_can_move = false;
                if(0 <= nly && nly < h && 0 <= nlx && nlx < w){
                    if(s[nly][nlx] != '#'){
                        L_can_move = true;
                    }
                }

                bool R_can_move = false;
                if(0 <= nry && nry < h && 0 <= nrx && nrx < w){
                    if(t[nry][nrx] != '#'){
                        R_can_move = true;
                    }
                }

                if(L_can_move && !R_can_move){
                    if(!visited[nly][nlx][cry][crx]){
                        if(s[nly][nlx] == '%') continue;
                        visited[nly][nlx][cry][crx] = true;
                        que.emplace(nly, nlx, cry, crx);
                    }
                }
                else if(!L_can_move && R_can_move){
                    if(!visited[cly][clx][nry][nrx]){
                        if(t[nry][nrx] == '%') continue;
                        visited[cly][clx][nry][nrx] = true;
                        que.emplace(cly, clx, nry, nrx);
                    }
                }
                else if(L_can_move && R_can_move){
                    if(!visited[nly][nlx][nry][nrx]){
                        if(s[nly][nlx] == '%' && t[nry][nrx] != '%') continue;
                        if(s[nly][nlx] != '%' && t[nry][nrx] == '%') continue;
                        visited[nly][nlx][nry][nrx] = true;
                        que.emplace(nly, nlx, nry, nrx);
                    }
                }
            }
        }

        if(!can_goal) cout << "No" << endl;
    }

    return 0;
}