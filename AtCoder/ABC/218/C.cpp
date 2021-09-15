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
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<string> s(n), t(n);
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++) cin >> t[i];

    int scnt = 0, tcnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scnt += s[i][j] == '#';
            tcnt += t[i][j] == '#';
        }
    }

    if(scnt != tcnt){
        cout << "No" << endl;
        return 0;
    }

    set<P> grid;
    bool first = true;
    int by = -1, bx = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(s[i][j] == '#'){
                if(first){
                    first = false;
                    by = i, bx = j;
                }
                else{
                    grid.emplace(i - by, j - bx);
                }
            }
        }
    }

    bool ans = false;
    for(int d=0; d<4; d++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(t[i][j] == '#'){
                    bool valid = true;
                    for(auto g : grid){
                        int cy = i + g.first, cx = j + g.second;
                        if(!(0 <= cy && cy < n && 0 <= cx && cx < n)) valid = false;
                        if(t[cy][cx] == '.') valid = false;
                        if(!valid) goto END;
                    }
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }

        END:;

        vector<string> nxt(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                nxt[i] += t[n - 1 - j][i];
            }
        }

        t = nxt;
    }

    cout << "No" << endl;

    return 0;
}