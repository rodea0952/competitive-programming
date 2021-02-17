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
    vector<vector<bool>> G(n, vector<bool>(n, false));
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b; a--, b--;
        G[a][b] = G[b][a] = true;
    }

    vector<bool> is_clique(1 << n, true);
    for(int bit=0; bit<(1<<n); bit++){
        vector<int> v;
        for(int i=0; i<n; i++){
            if(bit & (1 << i)) v.emplace_back(i);
        }

        for(int i=0; i<v.size(); i++){
            for(int j=0; j<i; j++){
                if(!G[v[i]][v[j]]) is_clique[bit] = false;
            }
        }
    }

    vector<int> dp(1 << n, inf);
    dp[0] = 0;
    for(int bit=0; bit<(1<<n); bit++){
        if(dp[bit] == inf) continue;
        int subset = bit ^ ((1 << n) - 1);
        for(int sbit=subset; sbit>0; --sbit&=subset){
            if(!is_clique[sbit]) continue;
            chmin(dp[bit | sbit], dp[bit] + 1);
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}