#pragma GCC optimize(O3)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

template <class T> inline T chmax(T &a, T &b) {a = max(a, b);}
template <class T> inline T chmin(T &a, T &b) {a = min(a, b);}

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

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

const int MAX_N = 2010;

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
    ll n, k; cin>>n>>k;

    calc(2000);

    for(int i=1; i<=k; i++){
        ll ans = comb(n - k + 1, i) * comb(k - 1, i - 1);
        cout << ans % MOD << endl;
    }
}