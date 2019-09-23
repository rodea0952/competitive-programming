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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int w, h; cin>>w>>h;
    int m[h][w];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin>>m[i][j];
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    bool valid = false;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(visited[i][j]) continue;

            queue<T> que;
            que.emplace(i, j, -1, -1);
            visited[i][j] = true;
            while(que.size()){
                int cy, cx, py, px;
                tie(cy, cx, py, px) = que.front(); que.pop();

                for(int k=0; k<4; k++){
                    int ny = cy + dy[k], nx = cx + dx[k];
                    if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
                    if(m[cy][cx] != m[ny][nx]) continue;
                    if(ny == py && nx == px) continue;

                    if(visited[ny][nx]) valid = true;
                    else{
                        visited[ny][nx] = true;
                        que.emplace(ny, nx, cy, cx);
                    }
                }
            }
        }
    }

    cout << (valid ? "possible" : "impossible") << endl;

    return 0;
}