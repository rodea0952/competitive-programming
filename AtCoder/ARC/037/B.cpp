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

vector<bool> visited(110);
bool is_tree;

void dfs(int cv, int pv, vector<vector<int>> &G){
    visited[cv] = true;

    for(auto nv : G[cv]){
        if(nv == pv) continue;
        if(visited[nv]) is_tree = false;
        if(!visited[nv]) dfs(nv, cv, G);
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        is_tree = true;
        bool is_root = false;
        if(!visited[i]){
            is_root = true;
            dfs(i, -1, G);
        }
        ans += (is_root && is_tree);
    }

    cout << ans << endl;

    return 0;
}