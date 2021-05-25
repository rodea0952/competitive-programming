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

vector<int> depth(200010), in(200010), out(200010);
vector<vector<int>> depth_list(200010);
int timer;

void dfs(int cv, vector<vector<int>> &G){
    in[cv] = timer++;
    depth_list[depth[cv]].emplace_back(in[cv]);
    for(auto nv : G[cv]){
        depth[nv] = depth[cv] + 1;
        dfs(nv, G);
    }
    out[cv] = timer++;
    return ;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> G(n);
    for(int i=1; i<n; i++){
        int p; cin>>p; p--;
        G[p].emplace_back(i);
    }

    dfs(0, G);

    int q; cin>>q;
    while(q--){
        int u, d; cin>>u>>d; u--;
        cout << upper_bound(all(depth_list[d]), out[u]) - lower_bound(all(depth_list[d]), in[u]) << endl;
    }

    return 0;
}