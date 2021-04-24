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

vector<int> value(110, 1);
vector<int> children_cnt(110, 0);
void dfs(int cv, int pv, vector<vector<T>> &G){
    for(auto nxt : G[cv]){
        int nv, cost, idx; tie(nv, cost, idx) = nxt;
        if(nv == pv) continue;
        dfs(nv, cv, G);
        children_cnt[cv] += children_cnt[nv];
        value[idx] = children_cnt[nv];
    }
    if(children_cnt[cv] == 0) children_cnt[cv] = 1;
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    vector<int> a(n-1), b(n-1), c(n-1);
    vector<vector<T>> G(n);
    for(int i=0; i<n-1; i++){
        cin>>a[i]>>b[i]>>c[i]; a[i]--, b[i]--;
        G[a[i]].emplace_back(b[i], c[i], i);
        G[b[i]].emplace_back(a[i], c[i], i);
    }

    dfs(0, -1, G);

    for(int i=0; i<n-1; i++) value[i] *= c[i];
    vector<int> dp(k + 1, 0);
    for(int i=0; i<n-1; i++){
        for(int j=k-c[i]; j>=0; j--){
            chmax(dp[c[i] + j], dp[j] + value[i]);
        }
    }

    ll ans = dp[k];
    for(int i=0; i<n-1; i++) ans += value[i];
    cout << ans << endl;

    return 0;
}