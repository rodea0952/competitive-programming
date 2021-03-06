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
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    int n, d; cin>>n>>d;
    vector<int> t(n), k(n);
    for(int i=0; i<n; i++) cin>>t[i]>>k[i];

    vector<vector<ll>> dp(n+10, vector<ll>(2, 0));
    dp[1][0] = t[0];
    dp[1][1] = k[0] - d;

    for(int i=1; i<n; i++){
        dp[i+1][0] = max(dp[i][0] + t[i], dp[i][1] + t[i] - d);
        dp[i+1][1] = max(dp[i][0] + k[i] - d, dp[i][1] + k[i]);
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
}