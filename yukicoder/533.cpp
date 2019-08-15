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

ll dp[1000010][4];

int main(){
    int n; cin>>n;

    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][2] = 1;
    for(int i=2; i<n; i++){
        dp[i+1][1] = (dp[i][2] + dp[i][3]) % MOD;
        dp[i+1][2] = (dp[i-1][3] + dp[i-1][1]) % MOD;
        dp[i+1][3] = (dp[i-2][1] + dp[i-2][2]) % MOD;
    }

    cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << endl;
}