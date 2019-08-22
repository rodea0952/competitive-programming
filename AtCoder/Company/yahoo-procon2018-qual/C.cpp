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

int n;
ll dp1[18][1<<18];
ll dp2[18][2][1<<18];

ll rec(int index, int turn, int S){
    ll &dp = dp2[index][turn][S];

    if(dp != INF) return dp;
    if(n <= index) return 0;

    ll ret;
    if(turn){
        // Takahashi
        ret = 0;
        chmax(ret, rec(index + 1, 0, S)); // sale
        chmax(ret, dp1[index][S]); // buy and finish
    }
    else{
        // Aoki
        ret = INF;
        for(int i=0; i<n; i++){
            if(S & (1 << i)){
                // stop i-th product
                chmin(ret, rec(index, 1, S ^ (1 << i)));
            }
        }
    }

    return dp = ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    for(int i=0; i<18; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<(1<<18); k++){
                dp2[i][j][k] = INF;
            }
        }
    }

    cin>>n;
    vector<ll> x(n), c(n), v(n);
    for(int i=0; i<n; i++) cin>>x[i];
    for(int i=0; i<n; i++) cin>>c[i];
    for(int i=0; i<n; i++) cin>>v[i];

    vector<ll> xsum(n+1, 0);
    vector<ll> cost((1<<n), 0), value((1<<n), 0);
    for(int i=0; i<n; i++) xsum[i+1] = xsum[i] + x[i];
    for(int bit=0; bit<(1<<n); bit++){
        for(int i=0; i<n; i++){
            if(bit & (1 << i)){
                cost[bit] += c[i];
                value[bit] += v[i];
            }
        }
    }

    for(int bit=0; bit<(1<<n); bit++){
        for(int i=0; i<n; i++){
            if(cost[bit] <= xsum[i+1]){
                dp1[i][bit] = max(dp1[i][bit], value[bit]);
            }
        }
    }

    for(int bit=0; bit<(1<<n); bit++){
        for(int i=0; i<n; i++){
            if(bit & (1 << i)) continue;

            for(int j=0; j<n; j++){
                dp1[j][bit | (1 << i)] = max(dp1[j][bit | (1 << i)], dp1[j][bit]);
            }
        }
    }

    cout << rec(0, 0, (1 << n) - 1) << endl;
}