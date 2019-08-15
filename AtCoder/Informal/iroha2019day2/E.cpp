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

const int MAX_N = 200010;

ll fact[MAX_N], finv[MAX_N];
ll comb(int n, int r){
    if(n < r || r < 0) return 0;
    return fact[n] * finv[n-r] % MOD * finv[r] % MOD;
}

ll calc(int n){
    fact[0] = finv[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        finv[i] = modpow(fact[i], MOD-2);
    }
}

int main(){
    ll n, m; cin>>n>>m;

    calc(200005);

    ll ans=0;
    for(int k=1; k<=min(n, m); k++){
        ans += comb(k, n-k) * comb(m-1, m-k);
        ans %= MOD;
    }

    cout << (comb(n+m-2, m-1) - ans + MOD) % MOD << endl;
}