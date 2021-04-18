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
struct LazySegmentTree{
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    using FP = function<M(M, int)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    FP fp;
    X ex;
    M em;
    vector<X> dat;
    vector<M> lazy;

    LazySegmentTree(vector<X> v, FX _fx, FA _fa, FM _fm, FP _fp, X _ex, M _em){
        fx = _fx, fa = _fa, fm = _fm, fp = _fp, ex = _ex, em = _em;
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        dat.resize(n*2, ex);
        lazy.resize(n*2, em);
        for(int i=0; i<sz; i++) dat[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) dat[i] = fx(dat[i*2+1], dat[i*2+2]);
    }

    void eval(int k, int len){
        if(lazy[k] == em) return ;

        if(k < n - 1){
            lazy[k*2+1] = fm(lazy[k*2+1], lazy[k]);
            lazy[k*2+2] = fm(lazy[k*2+2], lazy[k]);
        }

        dat[k] = fa(dat[k], fp(lazy[k], len));
        lazy[k] = em;
    }

    void update(int a, int b, M x, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k, r - l);
        if(a <= l && r <= b){
            lazy[k] = fm(lazy[k], x);
            eval(k, r - l);
        }
        else if(a < r && l < b){
            update(a, b, x, k*2+1, l, (l+r)/2);
            update(a, b, x, k*2+2, (l+r)/2, r);
            dat[k] = fx(dat[k*2+1], dat[k*2+2]);
        }
    }

    X query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return ex;
        
        eval(k, r - l);
        if(a <= l && r <= b) return dat[k];
        X vl = query(a, b, k*2+1, l, (l+r)/2);
        X vr = query(a, b, k*2+2, (l+r)/2, r);
        return fx(vl, vr);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, q; cin>>n>>m>>q;
    vector<int> tt(q), xx(q), yy(q);
    for(int i=0; i<q; i++) cin>>tt[i]>>xx[i]>>yy[i], xx[i]--;
    vector<ll> a(n, 0), b(m, 0);

    set<int> st;
    st.emplace(0);
    for(int i=0; i<q; i++) st.emplace(yy[i]);
    map<int, int> num2idx;
    int idx = 0;
    for(auto i : st) num2idx[i] = idx++;

    using X = ll;
    using M = ll;
    vector<X> acnt(idx, 0), bcnt(idx, 0);
    vector<X> asum(idx, 0), bsum(idx, 0);
    auto fx = [](X x, X y) -> X {return x + y;};
    auto fa = [](X x, M y) -> X {return x + y;};
    auto fm = [](M x, M y) -> M {return x + y;};
    auto fp = [](M x, ll y) -> M {return x * y;};
    X ex = 0;
    M em = 0;
    LazySegmentTree<X, M> acntseg(acnt, fx, fa, fm, fp, ex, em), bcntseg(bcnt, fx, fa, fm, fp, ex, em);
    LazySegmentTree<X, M> asumseg(asum, fx, fa, fm, fp, ex, em), bsumseg(bsum, fx, fa, fm, fp, ex, em);
    acntseg.update(0, 1, n);
    bcntseg.update(0, 1, m);

    ll ans = 0;
    for(int i=0; i<q; i++){
        int t = tt[i], x = xx[i], y = yy[i];
        if(t == 1){
            if(a[x] <= y){
                // - [0, a[x])
                ans -= bcntseg.query(0, num2idx[a[x]]) * a[x];
                // - [a[x], y)
                ans -= bsumseg.query(num2idx[a[x]], num2idx[y]);
                // + [0, y)
                ans += bcntseg.query(0, num2idx[y]) * y;
            }
            else{ // y < a[x]
                // - [0, a[x])
                ans -= bcntseg.query(0, num2idx[a[x]]) * a[x];
                // + [0, y)
                ans += bcntseg.query(0, num2idx[y]) * y;
                // + [y, a[x])
                ans += bsumseg.query(num2idx[y], num2idx[a[x]]);
            }
            acntseg.update(num2idx[a[x]], num2idx[a[x]] + 1, -1);
            asumseg.update(num2idx[a[x]], num2idx[a[x]] + 1, -a[x]);
            acntseg.update(num2idx[y], num2idx[y] + 1, 1);
            asumseg.update(num2idx[y], num2idx[y] + 1, y);
            a[x] = y;
        }
        else{
            if(b[x] <= y){
                // - [0, b[x])
                ans -= acntseg.query(0, num2idx[b[x]]) * b[x];
                // - [b[x], y)
                ans -= asumseg.query(num2idx[b[x]], num2idx[y]);
                // + [0, y)
                ans += acntseg.query(0, num2idx[y]) * y;
            }
            else{ // y < b[x]
                // - [0, b[x])
                ans -= acntseg.query(0, num2idx[b[x]]) * b[x];
                // + [0, y)
                ans += acntseg.query(0, num2idx[y]) * y;
                // + [y, b[x])
                ans += asumseg.query(num2idx[y], num2idx[b[x]]);
            }
            bcntseg.update(num2idx[b[x]], num2idx[b[x]] + 1, -1);
            bsumseg.update(num2idx[b[x]], num2idx[b[x]] + 1, -b[x]);
            bcntseg.update(num2idx[y], num2idx[y] + 1, 1);
            bsumseg.update(num2idx[y], num2idx[y] + 1, y);
            b[x] = y;
        }

        cout << ans << endl;
    }

    return 0;
}