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

    int n, p; cin>>n>>p;
    vector<P> ab(n);
    for(int i=0; i<n; i++){
        int A, B; cin>>A>>B;
        ab[i] = P(A, B);
    }
    sort(all(ab), greater<P>());

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        tie(a[i], b[i]) = ab[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(p+1, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<=p; j++){
            chmax(dp[i + 1][j], dp[i][j]);

            if(0 <= j - a[i]){
                chmax(dp[i + 1][j], dp[i][j - a[i]] + b[i]);
            }
        }
    }

    int ans = 0;
    for(int i=n-1; i>=0; i--){
        chmax(ans, dp[i][p] + b[i]);
    }

    cout << ans << endl;

    return 0;
}