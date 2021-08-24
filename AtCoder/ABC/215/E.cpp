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

    int n; string s; cin >> n >> s;

    vector<vector<vector<mint>>> dp(1010, vector<vector<mint>>(1030, vector<mint>(20, 0)));
    for(int i=0; i<n; i++){
        int cur = s[i] - 'A';
        for(int bit=0; bit<(1<<10); bit++){
            for(int j=0; j<10; j++){
                // i 回目のコンテストに出場しない
                dp[i + 1][bit][j] += dp[i][bit][j];
                if(cur == j){
                    // 最後に出場したコンテストと同じ種類の i 回目のコンテストに出場する
                    dp[i + 1][bit][j] += dp[i][bit][j];
                }
            }
        }

        for(int bit=0; bit<(1<<10); bit++){
            if(bit & (1 << cur)) continue;
            for(int j=0; j<10; j++){
                // 最後に出場したコンテストと異なる種類の i 回目のコンテストに出場する
                dp[i + 1][bit | (1 << cur)][cur] += dp[i][bit][j];
            }
        }

        // 初めて出場するコンテストが i 回目である
        dp[i + 1][1 << cur][cur] += 1;
    }

    mint ans = 0;
    for(int bit=0; bit<(1<<10); bit++){
        for(int j=0; j<10; j++){
            ans += dp[n][bit][j];
        }
    }

    cout << ans << endl;

    return 0;
}