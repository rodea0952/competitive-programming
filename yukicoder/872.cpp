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

int n;
ll ans = 0;

ll dfs(int cv, int pv, vector<vector<P>> &G){
    ll sum = 1;
    for(auto nxt : G[cv]){
        int nv, cost;
        tie(nv, cost) = nxt;

        if(nv == pv) continue;

        ll cnt = dfs(nv, cv, G);
        ans += cnt * (n - cnt) * cost;
        sum += cnt;
    }

    return sum;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    vector<vector<P>> G(n);
    for(int i=0; i<n-1; i++){
        int u, v, w; cin>>u>>v>>w;
        u--, v--;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    dfs(0, -1, G);

    cout << ans * 2 << endl;

    return 0;
}