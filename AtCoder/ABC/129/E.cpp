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

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    string s; cin>>s;
    int n = s.size();
    vector<vector<ll>> dp(n+1, vector<ll>(2, 0LL));
    dp[0][0] = 1;

    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            // (0, 0)
            (dp[i+1][0] += dp[i][0]) %= MOD;
        }
        else{
            // (0, 1), (1, 0)
            (dp[i+1][0] += dp[i][0] * 2) %= MOD;
            // (0, 0)
            (dp[i+1][1] += dp[i][0]) %= MOD;
        }

        // (0, 0), (0, 1), (1, 0)
        (dp[i+1][1] += dp[i][1] * 3) %= MOD;
    }

    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}