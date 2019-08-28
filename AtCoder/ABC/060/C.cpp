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

ll dp[60][60][2510];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a; cin>>n>>a;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin>>x[i];

    dp[0][0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            for(int k=0; k<=2500; k++){
                if(k + x[i] <= 2500){
                    dp[i+1][j+1][k+x[i]] += dp[i][j][k];
                }

                dp[i+1][j][k] += dp[i][j][k];
            }
        }
    }

    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans += dp[n][i][a*i];
    }

    cout << ans << endl;
}