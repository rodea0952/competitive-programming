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

    int h, w; cin >> h >> w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    vector<vector<int>> dist(h, vector<int>(w, inf));
    priority_queue<T, vector<T>, greater<T>> que;
    que.emplace(0, 0, 0);
    dist[0][0] = 0;
    while(que.size()){
        int cdist, cy, cx;
        tie(cdist, cy, cx) = que.top(); que.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i], nx = cx + dx[i];
            if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
            if(s[ny][nx] == '#') continue;

            if(dist[ny][nx] > dist[cy][cx]){
                dist[ny][nx] = dist[cy][cx];
                que.emplace(dist[ny][nx], ny, nx);
            }
        }

        for(int i=-2; i<=2; i++){
            for(int j=-2; j<=2; j++){
                if(4 == abs(i) + abs(j)) continue;
                int ny = cy + i, nx = cx + j;
                if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;

                if(dist[ny][nx] > dist[cy][cx] + 1){
                    dist[ny][nx] = dist[cy][cx] + 1;
                    que.emplace(dist[ny][nx], ny, nx);
                }
            }
        }
    }

    cout << dist[h - 1][w - 1] << endl;

    return 0;
}