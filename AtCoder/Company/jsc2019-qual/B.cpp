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

template <typename X, typename M>
class SegmentTree{
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    int n;
    FX fx;
    FA fa;
    X ex;
    vector<X> dat;

public:
    SegmentTree(vector<X> v, FX _fx, FA _fa, X _ex){
        fx = _fx, fa = _fa, ex = _ex;
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        dat.resize(n*2, ex);
        for(int i=0; i<sz; i++) dat[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) dat[i] = fx(dat[i*2+1], dat[i*2+2]);
    }

    void update(int i, X val){
        i += n - 1;
        dat[i] = fa(dat[i], val);
        while(i > 0){
            i = (i - 1) / 2;
            dat[i] = fx(dat[i*2+1], dat[i*2+2]);
        }
    }

    X query(int a, int b, int k=0, int l=0, int r=-1){
        if (r < 0) r = n;
        if (r <= a || b <= l) return ex;
        if (a <= l && r <= b) return dat[k];
        X lv = query(a, b, k*2+1, l, (l+r)/2);
        X rv = query(a, b, k*2+2, (l+r)/2, r);
        return fx(lv, rv);
    }
};

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

    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i], a[i]--;

    using X = ll;
    using M = ll;
    vector<X> b(2000, 0), c(2000, 0);
    auto fx = [](X x, X y) -> X {return x + y;};
    auto fa = [](X x, M y) -> X {return x + y;};
    X ex = 0;
    SegmentTree<X, M> segb(b, fx, fa, ex), segc(c, fx, fa, ex);
    mint bsum = 0, csum = 0;
    for(int i=0; i<n; i++){
        bsum += segb.query(a[i] + 1, 2000);
        segb.update(a[i], 1);
    }
    for(int i=0; i<2*n; i++){
        csum += segc.query(a[i % n] + 1, 2000);
        segc.update(a[i % n], 1);
    }
    mint dsum = csum - bsum * 2;

    cout << bsum * k + dsum * k * (k - 1) / 2 << endl;

    return 0;
}