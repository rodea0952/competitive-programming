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

const int MAX_N = 200001;

vector<vector<int>> G(MAX_N);
vector<ll> imos(MAX_N);
vector<ll> ans(MAX_N);

void dfs(int cv, int pv){
    if(pv != -1){
        imos[cv] += imos[pv];
        ans[cv] = imos[cv];
    }
    else{
        ans[cv] = imos[cv];
    }

    for(auto nv : G[cv]){
        if(nv == pv) continue;
        dfs(nv, cv);
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q; cin>>n>>q;
    
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for(int i=0; i<q; i++){
        int p, x; cin>>p>>x;
        p--;
        imos[p] += x;
    }

    dfs(0, -1);

    for(int i=0; i<n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }
}
