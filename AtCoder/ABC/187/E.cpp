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

vector<int> depth(200010, 0);
vector<ll> imos(200010, 0);
void dfs(int cv, int pv, vector<vector<int>> &G){
    for(auto nv : G[cv]){
        if(nv == pv) continue;
        depth[nv] = depth[cv] + 1;
        imos[nv] += imos[cv];
        dfs(nv, cv, G);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n - 1), b(n - 1);
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        cin>>a[i]>>b[i]; a[i]--, b[i]--;
        G[a[i]].emplace_back(b[i]);
        G[b[i]].emplace_back(a[i]);
    }

    dfs(0, -1, G);

    int q; cin>>q;
    while(q--){
        int t, e, x; cin>>t>>e>>x; e--;
        if(t == 1){
            if(depth[a[e]] < depth[b[e]]) imos[b[e]] -= x, imos[0] += x;
            else imos[a[e]] += x;
        }
        else{
            if(depth[a[e]] < depth[b[e]]) imos[b[e]] += x;
            else imos[a[e]] -= x, imos[0] += x;
        }
    }

    dfs(0, -1, G);

    for(int i=0; i<n; i++){
        cout << imos[i] << endl;
    }

    return 0;
}