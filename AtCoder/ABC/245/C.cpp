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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> ab(n, vector<int>(2));
    for(int i=0; i<n; i++) cin >> ab[i][0];
    for(int i=0; i<n; i++) cin >> ab[i][1];

    vector<vector<int>> dp(n + 1, vector<int> (2, -1));
    dp[1][0] = ab[0][0];
    dp[1][1] = ab[0][1];

    for(int i=1; i<n; i++){
        for(int j=0; j<2; j++){
            for(int l=0; l<2; l++){
                if(dp[i][j] == -1) continue;
                if(abs(dp[i][j] - ab[i][l]) <= k){
                    dp[i + 1][l] = ab[i][l];
                }
            }
        }
    }

    string ans = "Yes";
    if(dp[n][0] == -1 && dp[n][1] == -1){
        ans = "No";
    }
    
    cout << ans << endl;

    return 0;
}