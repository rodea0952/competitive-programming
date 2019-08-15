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

const ll MOD=998244353;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b/2) % MOD;
        return (d * d) % MOD;
    }
    else{
        return (a * modpow(a, b-1)) % MOD;
    }
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int sum = accumulate(a.begin(), a.end(), 0); 

    vector<vector<ll>> dp(n+10, vector<ll>(sum+10, 0));
    dp[0][0] = 1;
    auto dp2 = dp;
    for(int i=0; i<n; i++){
        for(int j=0; j<=sum+5; j++){
            // Red
            if(j - a[i] >= 0) (dp[i+1][j] += dp[i][j-a[i]]) %= MOD;
            // Blue or Green
            (dp[i+1][j] += dp[i][j] * 2) %= MOD;

            if(j - a[i] >= 0) (dp2[i+1][j] += dp2[i][j-a[i]]) %= MOD;
            (dp2[i+1][j] += dp2[i][j]) %= MOD;
        }
    }

    ll whole = modpow(3, n);
    ll lengthLarge=0;
    if(sum % 2){
        for(int i=sum/2+1; i<=sum; i++){
            (lengthLarge += dp[n][i] * 3) %= MOD;
        }

        cout << (whole - lengthLarge + MOD) % MOD << endl;
    }
    else{
        for(int i=sum/2; i<=sum; i++){
            (lengthLarge += dp[n][i] * 3) %= MOD;
        }

        ll halfSum = dp2[n][sum/2] * 3;

        cout << (whole - lengthLarge + halfSum + MOD) % MOD << endl;
    }
}