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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    vector<vector<int>> memo(n, vector<int>(11, -1));
    vector<int> ans(n, 0);

    int q; cin>>q;
    vector<int> v(q), d(q), c(q);
    for(int i=0; i<q; i++) cin>>v[i]>>d[i]>>c[i];

    for(int i=q-1; i>=0; i--){
        v[i]--;
        queue<T> que;
        que.emplace(v[i], -1, d[i]);
        while(que.size()){
            int cv, pv, dist;
            tie(cv, pv, dist) = que.front(); que.pop();

            bool valid = true;
            for(int i=dist; i<=10; i++){
                if(memo[cv][i] != -1) valid = false;
            }

            if(!valid) continue;

            memo[cv][dist] = c[i];
            if(ans[cv] == 0) ans[cv] = c[i];

            for(auto nv : G[cv]){
                if(nv == pv) continue;

                que.emplace(nv, cv, dist - 1);
            }
        }
    }

    for(int i=0; i<n; i++) cout << ans[i] << endl;

    return 0;
}