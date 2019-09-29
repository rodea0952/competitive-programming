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

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    vector<int> dp(n+1, 0);
    dp[1] = v[0];
    for(int i=1; i<n; i++){
        dp[i+1] = max(dp[i], dp[i-1] + v[i]);
    }

    int num = dp[n];
    vector<int> ans;
    for(int i=n-1; i>=0; i--){
        if(i == 0){
            ans.emplace_back(i);
            break;
        }

        if(dp[i+1] == dp[i]) continue;

        if(dp[i+1] - dp[i-1] == v[i]){
            ans.emplace_back(i);
            i--;
        }
    }

    sort(ans.begin(), ans.end());

    cout << dp[n] << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] + 1 << " \n"[i+1 == ans.size()];
    }

    return 0;
}