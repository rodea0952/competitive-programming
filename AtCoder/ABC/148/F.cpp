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

vector<int> Acnt(100010, -1), Tcnt(100010, -1);

void Adfs(int cv, vector<vector<int>> &G){
    for(auto nv : G[cv]){
        if(Acnt[nv] == -1){
            Acnt[nv] = Acnt[cv] + 1;
            Adfs(nv, G);
        }
    }
    return ;
}

void Tdfs(int cv, vector<vector<int>> &G){
    for(auto nv : G[cv]){
        if(Tcnt[nv] == -1 && Acnt[nv] >= Tcnt[cv] + 1){
            Tcnt[nv] = Tcnt[cv] + 1;
            Tdfs(nv, G);
        }
    }
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, u, v; cin>>n>>u>>v;
    u--, v--;
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    Acnt[v] = 0;
    Adfs(v, G);
    Tcnt[u] = 0;
    Tdfs(u, G);

    int ans = 0;
    for(int i=0; i<n; i++){
        if(Tcnt[i] != -1){
            chmax(ans, Acnt[i] - 1);
        }
    }

    cout << ans << endl;

    return 0;
}
