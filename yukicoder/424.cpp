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
    int sy, sx, gy, gx; cin>>sy>>sx>>gy>>gx;
    sy--, sx--, gy--, gx--;

    vector<string> b(h);
    for(int i=0; i<h; i++) cin>>b[i];

    queue<P> que;
    que.emplace(sy, sx);
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    visited[sy][sx] = true;

    bool valid = false;
    while(que.size()){
        int cy, cx;
        tie(cy, cx) = que.front(); que.pop();

        int cnum = b[cy][cx] - '0';

        if(cy == gy && cx == gx){
            valid = true;
            break;
        }

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(0 <= ny && ny < h && 0 <= nx && nx < w && !visited[ny][nx]){
                int nnum = b[ny][nx] - '0';
                if(abs(cnum - nnum) <= 1){
                    visited[ny][nx] = true;
                    que.emplace(ny, nx);
                }
            }

            int nny = ny + dy[i];
            int nnx = nx + dx[i];

            if(0 <= nny && nny < h && 0 <= nnx && nnx < w && !visited[nny][nnx]){
                int nnum = b[ny][nx] - '0';
                int nnnum = b[nny][nnx] - '0';
                if(cnum == nnnum && nnum < nnnum){
                    visited[nny][nnx] = true;
                    que.emplace(nny, nnx);
                }
            }
        }
    }

    if(valid) cout << "YES" << endl;
    else cout << "NO" << endl;
}