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

const int V = 100000;
vector<vector<int>> G(2*V);
vector<ll> cnt(2);
vector<bool> visited(2*V);

void dfs(int cv){
    visited[cv] = true;
    cnt[cv/V]++;
    
    for(auto nv : G[cv]){
        if(visited[nv]) continue;
        dfs(nv);
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        x--, y--;
        y += V;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    ll ans = 0;
    for(int i=0; i<V*2; i++){
        if(visited[i]) continue;
        cnt[0] = cnt[1] = 0LL;
        dfs(i);
        ans += cnt[0] * cnt[1];
    }

    ans -= n;
    cout << ans << endl;
}