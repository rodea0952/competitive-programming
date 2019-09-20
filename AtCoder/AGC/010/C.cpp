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

bool valid = true;
int root = 0;

int dfs(int cv, int pv, vector<vector<int>> &G, vector<ll> &a){

    ll sum = 0;
    bool have_child = false;
    for(auto nv : G[cv]){
        if(nv == pv) continue;
        have_child = true;
        ll cost = dfs(nv, cv, G, a);
        if(a[cv] < cost) valid = false;
        if(cost < 0) valid = false;
        sum += cost;
    }

    if(cv == root){
        if(a[root] != sum) valid = false;
    }

    if(!have_child){
        return a[cv];
    }
    else{
        if(a[cv] < a[cv] * 2 - sum) valid = false;
        return a[cv] * 2 - sum;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    while(G[root].size() > 1) root++;

    dfs(root, -1, G, a);

    cout << (valid ? "YES" : "NO") << endl;

    return 0;
}