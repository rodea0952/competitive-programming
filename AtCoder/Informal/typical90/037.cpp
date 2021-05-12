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
struct SegmentTree{
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    int n;
    FX fx;
    FA fa;
    X ex;
    vector<X> dat;

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int w, n; cin>>w>>n;
    vector<ll> l(n), r(n), v(n);
    for(int i=0; i<n; i++) cin>>l[i]>>r[i]>>v[i];

    using X = ll;
    using M = ll;
    vector<X> a(w + 1, -1);
    auto fx = [](X x, X y) -> X {return max(x, y);};
    auto fa = [](X x, M y) -> X {return y;};
    X ex = -INF;
    SegmentTree<X, M> seg(a, fx, fa, ex);
    seg.update(0, 0);

    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, -1));
    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=w; j++){
            chmax(dp[i + 1][j], dp[i][j]);
            int L = j - r[i], R = j - l[i];
            if(R < 0) continue;
            ll val = seg.query(L, R + 1);
            if(val < 0) continue;
            chmax(dp[i + 1][j], val + v[i]);
        }
        for(int j=0; j<=w; j++){
            seg.update(j, dp[i + 1][j]);
        }
    }

    cout << dp[n][w] << endl;

    return 0;
}