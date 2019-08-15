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

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, W; cin>>n>>W;
    vector<int> v(n), w(n);
    for(int i=0; i<n; i++) cin>>v[i]>>w[i];

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<=W; j++){
            chmax(dp[i+1][j], dp[i][j]);

            if(j + w[i] <= W){
                dp[i+1][j+w[i]] = max(dp[i][j+w[i]], dp[i+1][j] + v[i]);
            }
        }
    }

    cout << dp[n][W] << endl;
}