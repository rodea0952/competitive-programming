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

    int h, w, k; cin>>h>>w>>k;
    int sy, sx, gy, gx; cin>>sy>>sx>>gy>>gx;
    sy--, sx--, gy--, gx--;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    priority_queue<T, vector<T>, greater<T>> que;
    que.emplace(0, sy, sx);
    vector<vector<int>> dist(h, vector<int>(w, inf));
    dist[sy][sx] = 0;
    while(que.size()){
        int cdist, cy, cx;
        tie(cdist, cy, cx) = que.top(); que.pop();

        for(int i=0; i<4; i++){
            for(int j=1; j<=k; j++){
                int ny = cy + dy[i] * j, nx = cx + dx[i] * j;
                if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) break;
                if(s[ny][nx] == '@') break;

                if(dist[ny][nx] > cdist + 1){
                    dist[ny][nx] = cdist + 1;
                    que.emplace(dist[ny][nx], ny, nx);
                }
                else if(dist[ny][nx] == cdist + 1) continue;
                else break;
            }
        }
    }

    cout << (dist[gy][gx] == inf ? -1 : dist[gy][gx]) << endl;

    return 0;
}