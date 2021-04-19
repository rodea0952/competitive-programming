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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v; u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int k; cin>>k;
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> light(n, 0);
    for(int i=0; i<k; i++){
        int b; cin>>b; b--;
        light[b] = 1;
        que.emplace(a[b], b);
    }

    vector<int> ans;
    while(que.size()){
        int ca, cv; tie(ca, cv) = que.top(); que.pop();
        if(light[cv] == 0) continue;
        light[cv] = 0;
        ans.emplace_back(cv);
        for(auto nv : G[cv]){
            if(ca < a[nv]){
                light[nv] ^= 1;
                if(light[nv] == 1) que.emplace(a[nv], nv);
            }
        }
    }

    if(accumulate(all(light), 0) != 0){
        cout << -1 << endl;
    }
    else{
        cout << ans.size() << endl;
        for(auto i : ans) cout << i + 1 << endl;
    }

    return 0;
}