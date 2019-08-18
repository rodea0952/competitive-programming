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

ll dp[1010][1010][5];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<string> s(m);
    for(int i=0; i<m; i++) cin>>s[i];
    s.push_back("");

    dp[0][0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=m; j++){
            for(int k=0; k<3; k++){
                for(int l=0; l<=9; l++){
                    if(i == 0 && l == 0) continue;

                    int sum_mod3 = (k * 10 + l) % 3;

                    if(sum_mod3 % 3 == 0 && l % 5 == 0){
                        if(s[j] == "FizzBuzz"){
                            (dp[i+1][j+1][sum_mod3] += dp[i][j][k]) %= MOD;
                        }
                    }
                    else if(sum_mod3 % 3 == 0){
                        if(s[j] == "Fizz"){
                            (dp[i+1][j+1][sum_mod3] += dp[i][j][k]) %= MOD;
                        }
                    }
                    else if(l % 5 == 0){
                        if(s[j] == "Buzz"){
                            (dp[i+1][j+1][sum_mod3] += dp[i][j][k]) %= MOD;
                        }
                    }
                    else{
                        (dp[i+1][j][sum_mod3] += dp[i][j][k]) %= MOD;
                    }
                }
            }
        }
    }

    ll ans = (dp[n][m][0] + dp[n][m][1] + dp[n][m][2]) % MOD;
    cout << ans << endl;
}