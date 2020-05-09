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

bool dp[60][2510][2510];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin>>t[i];

    dp[0][0][0] = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<=2500; j++){
            for(int k=0; k<=2500; k++){
                if(!dp[i][j][k]) continue;

                if(j + t[i] <= 2500) dp[i+1][j+t[i]][k] = true;
                if(k + t[i] <= 2500) dp[i+1][j][k+t[i]] = true;
                dp[i+1][j][k] = true;
            }
        }
    }

    int ans = inf, tsum = accumulate(all(t), 0);
    for(int i=0; i<=2500; i++){
        for(int j=0; j<=2500; j++){
            if(!dp[n][i][j]) continue;

            chmin(ans, max({i, j, tsum - i - j}));
        }
    }

    cout << ans << endl;

    return 0;
}