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

    int n, m; cin>>n>>m;
    vector<bool> use(10, false);
    for(int i=0; i<m; i++){
        int a; cin>>a;
        use[a] = true;
    }

    vector<int> match = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    vector<int> dp(n+1, -inf);
    dp[0] = 0;
    for(int i=1; i<=9; i++){
        if(!use[i]) continue;
        for(int j=0; j<=n; j++){
            if(j - match[i] >= 0) chmax(dp[j], dp[j - match[i]] + 1);
        }
    }

    string ans;
    for(int i=n; i>0; ){
        for(int j=9; j>=1; j--){
            if(!use[j]) continue;
            if(i - match[j] >= 0 && dp[i - match[j]] + 1 == dp[i]){
                i -= match[j];
                ans += to_string(j);
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}