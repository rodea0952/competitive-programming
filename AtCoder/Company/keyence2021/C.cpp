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

    int h, w, k; cin>>h>>w>>k;
    vector<vector<char>> s(h, vector<char>(w, '?'));
    for(int i=0; i<k; i++){
        int H, W; cin>>H>>W; H--, W--;
        char c; cin>>c;
        s[H][W] = c;
    }

    vector<vector<mint>> dp(h + 1, vector<mint>(w + 1, 0));
    dp[0][0] = 1;
    mint div3 = modpow(3, MOD - 2);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] == 'X'){
                if(j + 1 < w) dp[i][j + 1] += dp[i][j];
                if(i + 1 < h) dp[i + 1][j] += dp[i][j];
            }
            else if(s[i][j] == 'R'){
                if(j + 1 < w) dp[i][j + 1] += dp[i][j];
            }
            else if(s[i][j] == 'D'){
                if(i + 1 < h) dp[i + 1][j] += dp[i][j];
            }
            else{
                if(j + 1 < w) dp[i][j + 1] += dp[i][j] * 2 * div3;
                if(i + 1 < h) dp[i + 1][j] += dp[i][j] * 2 * div3;
            }
        }
    }

    cout << dp[h - 1][w - 1] * modpow(3, h * w - k) << endl;

    return 0;
}