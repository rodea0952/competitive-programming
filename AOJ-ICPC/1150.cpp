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
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 1, 1, 1, 1, 2, 2, 2, 3};
int dy[]={2, 1, 0, -1, -2, 1, 0, -1, 0};

int L = 0, R = 1;

int main(){
    while(1){
        int w, h; cin>>w>>h;
        if(w == 0) return 0;
        
        vector<vector<string>> s(h, vector<string>(w));
        queue<T> lque, rque;
        int ldist[h][w][2], rdist[h][w][2];
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                for(int k=0; k<2; k++){
                    ldist[i][j][k] = 1e9;
                    rdist[i][j][k] = 1e9;
                }
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>s[i][j];
                
                if(s[i][j] == "S"){
                    ldist[i][j][L] = 0;
                    rdist[i][j][R] = 0;
                    lque.push(T(i, j, 0));
                    rque.push(T(i, j, 0));
                }
            }
        }

        // from left
        int ans = 1e9;
        while(lque.size()){
            int cy, cx, cnt;
            tie(cy, cx, cnt) = lque.front();
            lque.pop();

            int cleg, nleg;
            if(cnt % 2 == 0){
                cleg = L;
                nleg = R;
            }
            else{
                cleg = R;
                nleg = L;
            }

            for(int i=0; i<9; i++){
                int ny = cy + (cnt % 2 == 0 ? dy[i] : - dy[i]);
                int nx = cx + (cnt % 2 == 0 ? dx[i] : - dx[i]);

                if(0 <= ny && ny < h && 0 <= nx && nx < w){
                    if("1" <= s[ny][nx] && s[ny][nx] <= "9"){
                        if(ldist[cy][cx][cleg] + stoi(s[ny][nx]) < ldist[ny][nx][nleg]){
                            ldist[ny][nx][nleg] = ldist[cy][cx][cleg] + stoi(s[ny][nx]);
                            lque.push(T(ny, nx, cnt + 1));
                        }
                    }
                    else if(s[ny][nx] == "T"){
                        ans = min(ans, ldist[cy][cx][cleg]);
                    }
                }
            }
        }

        // from right
        while(rque.size()){
            int cy, cx, cnt;
            tie(cy, cx, cnt) = rque.front();
            rque.pop();

            int cleg, nleg;
            if(cnt % 2 == 1){
                cleg = L;
                nleg = R;
            }
            else{
                cleg = R;
                nleg = L;
            }

            for(int i=0; i<9; i++){
                int ny = cy + (cnt % 2 == 1 ? dy[i] : - dy[i]);
                int nx = cx + (cnt % 2 == 1 ? dx[i] : - dx[i]);

                if(0 <= ny && ny < h && 0 <= nx && nx < w){
                    if("1" <= s[ny][nx] && s[ny][nx] <= "9"){
                        if(rdist[cy][cx][cleg] + stoi(s[ny][nx]) < rdist[ny][nx][nleg]){
                            rdist[ny][nx][nleg] = rdist[cy][cx][cleg] + stoi(s[ny][nx]);
                            rque.push(T(ny, nx, cnt + 1));
                        }
                    }
                    else if(s[ny][nx] == "T"){
                        ans = min(ans, rdist[cy][cx][cleg]);
                    }
                }
            }
        }

        cout << (ans == 1e9 ? -1 : ans) << endl;
    }
}