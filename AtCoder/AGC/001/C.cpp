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

int n, k;
vector<vector<int>> G(2000);
vector<bool> visited(2000);

void dfs(int cv, int pv, int depth){
    if(k / 2 < depth) return ;

    visited[cv] = true;
    for(auto nv : G[cv]){
        if(nv == pv) continue;
        dfs(nv, cv, depth + 1);
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    vector<P> edge;
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        edge.emplace_back(a, b);
    }

    int ans = inf;
    if(k % 2 == 0){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[j] = false;
            }

            dfs(i, -1, 0);

            int cnt = 0;
            for(int j=0; j<n; j++){
                cnt += (!visited[j]);
            }
            chmin(ans, cnt);
        }
    }
    else{
        for(int i=0; i<n-1; i++){
            int u, v;
            tie(u, v) = edge[i];

            for(int j=0; j<n; j++){
                visited[j] = false;
            }

            dfs(u, -1, 0);
            dfs(v, -1, 0);
            
            int cnt = 0;
            for(int j=0; j<n; j++){
                cnt += (!visited[j]);
            }
            chmin(ans, cnt);
        }
    }

    cout << ans << endl;
}