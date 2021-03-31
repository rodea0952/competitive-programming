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
using T = tuple<ll, ll, ll>;

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
    vector<int> x(n), c(n);
    for(int i=0; i<n; i++) cin>>x[i]>>c[i], c[i]--;

    set<int> kinds;
    kinds.emplace(-1);
    vector<set<int>> color(n);
    for(int i=0; i<n; i++){
        kinds.emplace(c[i]);
        color[c[i]].emplace(x[i]);
    }

    priority_queue<T, vector<T>, greater<T>> que;
    // 時間、座標、色
    que.emplace(0, 0, -1);
    ll ans = INF;
    map<ll, ll> dp;
    while(que.size()){
        ll ct, ci, cc; tie(ct, ci, cc) = que.top(); que.pop();
        // cout << ct << " " << ci << " " << cc + 1 << endl;
        auto itr1 = next(kinds.find(cc));

        if(itr1 == kinds.end()){
            chmin(ans, ct + abs(ci));
            continue;
        }

        int nc = *itr1;
        auto itr2 = color[nc].lower_bound(ci);
        if(itr2 == color[nc].begin()){
            int ni = *prev(color[nc].end());
            if(dp.count(ni) == 0 || ct + (ni - ci) < dp[ni]){
                dp[ni] = ct + (ni - ci);
                que.emplace(ct + (ni - ci), ni, nc);
            }
        }
        else if(itr2 == color[nc].end()){
            int ni = *color[nc].begin();
            if(dp.count(ni) == 0 || ct + (ci - ni) < dp[ni]){
                dp[ni] = ct + (ci - ni);
                que.emplace(ct + (ci - ni), ni, nc);
            }
        }
        else{
            int nil = *color[nc].begin(), nir = *prev(color[nc].end());
            if(dp.count(nil) == 0 || ct + (nir - ci) + (nir - nil) < dp[nil]){
                dp[nil] = ct + (nir - ci) + (nir - nil);
                que.emplace(ct + (nir - ci) + (nir - nil), nil, nc);
            }
            if(dp.count(nir) == 0 || ct + (ci - nil) + (nir - nil) < dp[nir]){
                dp[nir] = ct + (ci - nil) + (nir - nil);
                que.emplace(ct + (ci - nil) + (nir - nil), nir, nc);
            }
        }
    }

    cout << ans << endl;

    return 0;
}