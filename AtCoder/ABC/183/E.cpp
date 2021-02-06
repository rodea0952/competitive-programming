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

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

class mint{
public:
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

    int h, w; cin>>h>>w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    vector<vector<mint>> dp(h, vector<mint>(w, 0));
    vector<vector<mint>> wsum(h, vector<mint>(w, 0));
    vector<vector<mint>> hsum(h, vector<mint>(w, 0));
    vector<vector<mint>> dsum(h, vector<mint>(w, 0));

    dp[0][0] = 1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] == '#') continue;

            if(0 <= i - 1) dp[i][j] += wsum[i - 1][j]; 
            if(0 <= j - 1) dp[i][j] += hsum[i][j - 1];
            if(0 <= i - 1 && 0 <= j - 1) dp[i][j] += dsum[i - 1][j - 1];

            if(0 <= i - 1) wsum[i][j] = wsum[i - 1][j] + dp[i][j];
            else wsum[i][j] = dp[i][j];

            if(0 <= j - 1) hsum[i][j] = hsum[i][j - 1] + dp[i][j];
            else hsum[i][j] = dp[i][j];

            if(0 <= i - 1 && 0 <= j - 1) dsum[i][j] = dsum[i - 1][j - 1] + dp[i][j];
            else dsum[i][j] = dp[i][j];
        }
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}