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

const int MAX_N = 100020;
ll fact[MAX_N], finv[MAX_N];
ll comb(int n, int r){
    if(n < r || r < 0) return 0;
    return fact[n] * finv[n-r] % MOD * finv[r] % MOD;
}

void calc(int n){
    fact[0] = finv[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        finv[i] = modpow(fact[i], MOD-2);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    calc(100010);

    int n, k; cin>>n>>k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    vector<ll> pbase(n, 0);
    for(int i=0; i<n; i++){
        pbase[i] = comb(i, k - 1);
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += pbase[i] * a[i];
        ans %= MOD;
        ans -= (pbase[n - i - 1] * a[i]) % MOD;
        ans += MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
