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

    int n, t; cin>>n>>t;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];

    vector<vector<int>> dp1(n+2, vector<int>(t, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<t; j++){
            dp1[i+1][j] = dp1[i][j];
            if(j - a[i] >= 0) chmax(dp1[i+1][j], dp1[i][j - a[i]] + b[i]);
        }
    }

    vector<vector<int>> dp2(n+2, vector<int>(t, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<t; j++){
            dp2[i+1][j] = dp2[i][j];
            if(j - a[n-1-i] >= 0) chmax(dp2[i+1][j], dp2[i][j - a[n-1-i]] + b[n-1-i]);
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<t; j++){
            int head = dp1[i-1][j];
            int tail = dp2[n-i][t-1-j];
            chmax(ans, head + tail + b[i-1]);
        }
    }

    cout << ans << endl;
    
    return 0;
}