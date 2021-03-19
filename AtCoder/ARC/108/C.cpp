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
vector<bool> visited(100010, false);
vector<int> ans(100010, 0);

void dfs(int cv, vector<vector<P>> &G){
    for(auto nxt : G[cv]){
        int nv, num; tie(nv, num) = nxt;
        if(visited[nv]) continue;
        visited[nv] = true;
        ans[nv] = (num + (ans[cv] == num)) % n;
        dfs(nv, G);
    }
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m; cin>>n>>m;
    vector<vector<P>> G(n);
    for(int i=0; i<m; i++){
        int u, v, c; cin>>u>>v>>c; u--, v--, c--;
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }

    visited[0] = true;
    dfs(0, G);

    for(int i=0; i<n; i++){
        cout << ans[i] + 1 << endl;
    }

    return 0;
}