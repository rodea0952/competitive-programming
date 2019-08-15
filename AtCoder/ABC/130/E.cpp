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
#define chmin(a, b) ((a) = min((a), (b)))
#define chmax(a, b) ((a) = max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

#define int long long

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

signed main(){
    int n, m; cin>>n>>m;
    vector<int> s(n), t(m);
    for(int i=0; i<n; i++) cin>>s[i];
    for(int i=0; i<m; i++) cin>>t[i];

    vector<vector<ll>> dp(2010, vector<ll>(2010, 0));
    ll num = 1;
    for(int i=0; i<n; i++){
        if(s[i] == t[0]){
            num++; 
        }
        
        dp[1][i+1] = num;
    }

    num = 1;
    for(int i=0; i<m; i++){
        if(s[0] == t[i]){
            num++;
        }
        
        dp[i+1][1] = num;
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(s[j] == t[i]){
                (dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j]) %= MOD;
            }
            else{
                (dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + MOD) %= MOD;
            }
        }
    }

    cout << dp[m][n] % MOD << endl;
}
