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

constexpr int MOD = 998244353;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct mint{
    ll x;
    constexpr mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
    constexpr mint operator-() const{
        return mint(-x);
    }
    constexpr mint& operator+=(const mint& a){
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr mint& operator-=(const mint& a){
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    constexpr mint& operator*=(const mint& a){
        (x *= a.x) %= MOD;
        return *this;
    }
    constexpr mint operator+(const mint& a) const{
        mint res(*this);
        return res += a;
    }
    constexpr mint operator-(const mint& a) const{
        mint res(*this);
        return res -= a;
    }
    constexpr mint operator*(const mint& a) const{
        mint res(*this);
        return res *= a;
    }
    constexpr mint pow(ll t) const{
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime MOD
    constexpr mint inv() const{
        return pow(MOD - 2);
    }
    constexpr mint& operator/=(const mint& a){
        return (*this) *= a.inv();
    }
    constexpr mint operator/(const mint& a) const{
        mint res(*this);
        return res /= a;
    }
};
istream& operator>>(istream& is, mint& a) {return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) {return os << a.x;}

mint modpow(mint a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        mint d = modpow(a, b / 2);
        return d * d;
    }
    else{
        return a * modpow(a, b - 1);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    vector<P> ab(n);
    for(int i=0; i<n; i++){
        ab[i] = P(a[i], b[i]);
    }

    sort(all(ab));

    for(int i=0; i<n; i++){
        a[i] = ab[i].first;
        b[i] = ab[i].second;
    }

    const int MAX_A = 5000;
    // dp[i][j] := i 番目まで見て、かつ i 番目を使って、B の総和が j となる通り数
    vector<vector<mint>> dp(n + 1, vector<mint>(MAX_A + 1, 0));
    dp[0][0] = 1;

    // dpsum[j] := dp[これまで][j] の総和
    vector<mint> dpsum(MAX_A + 1, 0);
    dpsum[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<=MAX_A; j++){
            if(j >= b[i]) dp[i + 1][j] += dpsum[j - b[i]];
        }
        for(int j=0; j<=MAX_A; j++){
            dpsum[j] += dp[i + 1][j];
        }
    }
    
    mint ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=a[i]; j++){
            ans += dp[i + 1][j];
        }
    }

    cout << ans << endl;

    return 0;
}