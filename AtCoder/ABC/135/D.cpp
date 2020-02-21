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

    string s; cin>>s;
    int n = s.size();

    vector<vector<ll>> dp(n+1, vector<ll>(13, 0));

    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int pre=0; pre<=12; pre++){
            if(s[i] == '?'){
                for(int j=0; j<=9; j++){
                    int num = pre * 10 + j;
                    dp[i+1][num%13] += dp[i][pre];
                    dp[i+1][num%13] %= MOD;
                }
            }
            else{
                int cur = s[i] - '0';
                int num = pre * 10 + cur;
                dp[i+1][num%13] += dp[i][pre];
                dp[i+1][num%13] %= MOD;
            }
        }
    }

    cout << dp[n][5] << endl;

    return 0;
}