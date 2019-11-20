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

vector<int> parent(110, -1);

void dfs(int cv, int pv, vector<vector<int>> &G){
    for(auto nv : G[cv]){
        if(pv == nv) continue;
        parent[nv] = cv;
        dfs(nv, cv, G);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, x; cin>>n>>x;
    x--;
    vector<int> h(n);
    for(int i=0; i<n; i++) cin>>h[i];
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    dfs(x, -1, G);

    set<int> passed;
    for(int i=0; i<n; i++){
        if(h[i]){
            for(int j=i; j!=-1; j=parent[j]){
                passed.emplace(j);
            }
        }
    }

    passed.erase(x);

    cout << passed.size() * 2 << endl;

    return 0;
}