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

int judge(char my, char your, int x, int y){
    if(my == 'G'){
        if(your == 'G') return y;
        else if(your == 'C') return x;
        else return 0;
    }
    else if(my == 'C'){
        if(your == 'G') return 0;
        else if(your == 'C') return y;
        else return x;
    }
    else{
        if(your == 'G') return x;
        else if(your == 'C') return 0;
        else return y;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, k, x, y; cin>>n>>m>>k>>x>>y;
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for(int i=0; i<n; i++){
        G[i].emplace_back(i);
    }

    vector<char> c(n);
    for(int i=0; i<n; i++) cin>>c[i];
    vector<char> define(k);
    for(int i=0; i<k; i++){
        int d; cin>>d;
        d--;
        define[i] = c[d];
    }

    queue<P> que;
    que.emplace(0, 0);
    vector<vector<int>> dp(2001, vector<int>(2000, -1));
    dp[0][0] = 0;
    while(que.size()){
        int cv, turn;
        tie(cv, turn) = que.front(); que.pop();

        for(auto nv : G[cv]){
            char my = c[nv];
            char your = define[turn];

            int cost = judge(my, your, x, y);

            if(dp[turn+1][nv] < dp[turn][cv] + cost){
                dp[turn+1][nv] = dp[turn][cv] + cost;
                if(turn + 1 < k) que.emplace(nv, turn + 1);
            }
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        chmax(ans, dp[k][i]);
    }

    cout << ans << endl;
}