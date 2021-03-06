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
class LazySegmentTree{
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

public:
    LazySegmentTree(vector<X> v, FX _fx, FA _fa, FM _fm, FP _fp, X _ex, M _em){
        fx = _fx, fa = _fa, fm = _fm, fp = _fp, ex = _ex, em = _em;
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        dat.resize(2 * n, ex);
        lazy.resize(2 * n, em);
        for(int i=0; i<sz; i++) dat[i + n - 1] = v[i];
        for(int i=n-2; i>=0; i--) dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    void eval(int k, int len){
        if(lazy[k] == em) return ;

        if(k < n - 1){
            lazy[2 * k + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[2 * k + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }

        dat[k] = fa(dat[k], fp(lazy[k], len));
        lazy[k] = em;
    }

    void update(int a, int b, M x, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        eval(k, r - l);
        if(a <= l && r <= b){
            lazy[k] = fm(lazy[k], x);
            eval(k, r - l);
        }
        else if(a < r && l < b){
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    X query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return ex;
        
        eval(k, r - l);
        if(a <= l && r <= b) return dat[k];
        X vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        X vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return fx(vl, vr);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q; cin>>n>>q;

    using X = ll;
    using M = ll;
    vector<X> a(n, 0);
    auto fx = [](X x, X y) -> X {return x + y;};
    auto fa = [](X x, M y) -> X {return x + y;};
    auto fm = [](M x, M y) -> M {return x + y;};
    auto fp = [](M x, ll y) -> M {return x;};
    X ex = 0;
    M em = 0;
    LazySegmentTree<X, M> seg(a, fx, fa, fm, fp, ex, em);

    while(q--){
        int op; cin>>op;
        if(op == 0){
            int x; cin>>x; x--;
            ll y; cin>>y;
            seg.update(x, x + 1, y);
        }
        else{
            int x, y; cin>>x>>y; x--, y--;
            cout << seg.query(x, y + 1) << endl;
        }
    }

    return 0;
}
