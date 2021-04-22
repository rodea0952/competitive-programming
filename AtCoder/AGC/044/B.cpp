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

    int n; cin>>n;
    vector<int> p(n * n);
    for(int i=0; i<n*n; i++) cin>>p[i], p[i]--;

    vector<int> cost(n * n);
    for(int i=0; i<n*n; i++){
        int y = i / n, x = i % n;
        cost[i] = min({y, n - 1 - y, x, n - 1 - x});
    }

    // 計算量は que に入る回数に依存
    // N * N の正方形全てのマスのコストが N でも O(N^3) で抑えられる
    int ans = 0;
    vector<bool> sit(n * n, true);
    for(int i=0; i<n*n; i++){
        ans += cost[p[i]];
        sit[p[i]] = false;
        queue<P> que;
        que.emplace(p[i] / n, p[i] % n);
        while(que.size()){
            int cy, cx; tie(cy, cx) = que.front(); que.pop();
            for(int j=0; j<4; j++){
                int ny = cy + dy[j], nx = cx + dx[j];
                if(!(0 <= ny && ny < n && 0 <= nx && nx < n)) continue;
                if(cost[ny * n + nx] > cost[cy * n + cx] + int(sit[cy * n + cx])){
                    cost[ny * n + nx] = cost[cy * n + cx] + int(sit[cy * n + cx]);
                    que.emplace(ny, nx);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}