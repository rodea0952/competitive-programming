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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    vector<int> a(n);
    vector<int> plus, minus;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i] < 0) minus.emplace_back(a[i]);
        else plus.emplace_back(a[i]);
    }

    int psz = plus.size(), msz = minus.size();
    bool ans_plus = false;
    if(psz > 0){
        if(n == k){
            if(msz % 2 == 0) ans_plus = true;
        }
        else ans_plus = true;
    }
    else{
        if(k % 2 == 0) ans_plus = true;
    }

    mint ans = 1;
    if(!ans_plus){
        sort(all(a), [](int x, int y){return abs(x) < abs(y);});
        for(int i=0; i<k; i++) ans *= a[i];    
    }
    else{
        sort(all(plus));
        sort(all(minus), greater<int>());

        if(k % 2){
            ans *= plus.back(); plus.pop_back();
        }

        vector<ll> p;
        while(plus.size() >= 2){
            ll cur = plus.back(); plus.pop_back();
            cur *= plus.back(); plus.pop_back();
            p.emplace_back(cur);
        }
        while(minus.size() >= 2){
            ll cur = minus.back(); minus.pop_back();
            cur *= minus.back(); minus.pop_back();
            p.emplace_back(cur);
        }
        sort(all(p), greater<ll>());

        for(int i=0; i<k/2; i++) ans *= p[i];
    }

    cout << ans << endl;

    return 0;
}