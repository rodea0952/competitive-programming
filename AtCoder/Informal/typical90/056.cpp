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

    int n, s; cin>>n>>s;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    dp[0][0] = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<=s; j++){
            if(j + a[i] <= s) dp[i + 1][j + a[i]] = dp[i + 1][j + a[i]] || dp[i][j];
            if(j + b[i] <= s) dp[i + 1][j + b[i]] = dp[i + 1][j + b[i]] || dp[i][j];
        }
    }

    if(!dp[n][s]){
        cout << "Impossible" << endl;
        return 0;
    }

    string ans = "";
    while(n > 0){
        if(s - a[n - 1] >= 0 && dp[n][s] && dp[n - 1][s - a[n - 1]]){
            s -= a[n - 1];
            n--;
            ans += "A";
        }
        else{
            s -= b[n - 1];
            n--;
            ans += "B";
        }
    }

    reverse(all(ans));

    cout << ans << endl;

    return 0;
}