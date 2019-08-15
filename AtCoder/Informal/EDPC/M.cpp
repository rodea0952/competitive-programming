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

ll dp[110][100010];

int main(){
    int n, k; cin>>n>>k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        vector<ll> sum(k+10, 0);

        for(int j=0; j<=k; j++){
            sum[j+1] = sum[j] + dp[i][j];
        }

        for(int j=0; j<=k; j++){
            dp[i+1][j] += (sum[j+1] - sum[max(0LL, j-a[i])]);
            dp[i+1][j] %= MOD;
        }
    }
    
    cout << dp[n][k] << endl;
}