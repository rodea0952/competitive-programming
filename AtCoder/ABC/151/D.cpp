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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w; cin>>h>>w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    int ans = 0;
    for(int sh=0; sh<h; sh++){
        for(int sw=0; sw<w; sw++){
            if(s[sh][sw] == '#') continue;
            for(int gh=0; gh<h; gh++){
                for(int gw=0; gw<w; gw++){
                    if(s[gh][gw] == '#') continue;
                    if(sh == gh && sw == gw) continue;
                    
                    queue<T> que;
                    que.emplace(sh, sw, 0);
                    vector<vector<bool>> visited(h, vector<bool>(w, false));
                    visited[sh][sw] = true;
                    while(que.size()){
                        int cy, cx, cnt;
                        tie(cy, cx, cnt) = que.front();
                        que.pop();

                        if(cy == gh && cx == gw){
                            chmax(ans, cnt);
                            break;
                        }

                        for(int i=0; i<4; i++){
                            int ny = cy + dy[i], nx = cx + dx[i];

                            if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
                            if(visited[ny][nx]) continue;
                            if(s[ny][nx] == '#') continue;

                            visited[ny][nx] = true;
                            que.emplace(ny, nx, cnt + 1);
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
