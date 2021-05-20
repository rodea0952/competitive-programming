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

    int n, k; cin>>n>>k;
    vector<ll> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    vector<ll> cost(1 << n, 0);
    for(int bit=0; bit<(1<<n); bit++){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(!(bit & (1 << i))) continue;
                if(!(bit & (1 << j))) continue;
                ll dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                chmax(cost[bit], dist);
            }
        }
    }

    vector<vector<ll>> dp(1 << n, vector<ll>(k + 1, 3 * INF));
    dp[0][0] = 0; 
    for(int bit=0; bit<(1<<n); bit++){
        int subset = bit ^ ((1 << n) - 1);
        for(int i=0; i<k; i++){
            for(int sbit=subset; sbit>0; --sbit&=subset){
                chmin(dp[bit | sbit][i + 1], max(dp[bit][i], cost[sbit]));
            }
        }
    }

    cout << dp[(1 << n) - 1][k] << endl;

    return 0;
}