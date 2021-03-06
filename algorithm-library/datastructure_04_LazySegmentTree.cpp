/*
Range Minimum Query and Range Update Query
using X = ll;
using M = ll;
vector<X> a(n, INF);
auto fx = [](X x, X y) -> X {return min(x, y);};
auto fa = [](X x, M y) -> X {return y;};
auto fm = [](M x, M y) -> M {return y;};
auto fp = [](M x, ll y) -> M {return x;};
X ex = INF;
M em = INF;
LazySegmentTree<X, M> seg(a, fx, fa, fm, fp, ex, em);

Range Sum Query and Range Add Query
using X = ll;
using M = ll;
vector<X> a(n, 0);
auto fx = [](X x, X y) -> X {return x + y;};
auto fa = [](X x, M y) -> X {return x + y;};
auto fm = [](M x, M y) -> M {return x + y;};
auto fp = [](M x, ll y) -> M {return x * y;};
X ex = 0;
M em = 0;
LazySegmentTree<X, M> seg(a, fx, fa, fm, fp, ex, em);

Range Minimum Query and Range Add Query
using X = ll;
using M = ll;
vector<X> a(n, 0);
auto fx = [](X x, X y) -> X {return min(x, y);};
auto fa = [](X x, M y) -> X {return x + y;};
auto fm = [](M x, M y) -> M {return x + y;};
auto fp = [](M x, ll y) -> M {return x;};
X ex = INF;
M em = 0;
LazySegmentTree<X, M> seg(a, fx, fa, fm, fp, ex, em);

Range Sum Query and Range Update Query
using X = ll;
using M = ll;
vector<X> a(n, 0);
auto fx = [](X x, X y) -> X {return x + y;};
auto fa = [](X x, M y) -> X {return y;};
auto fm = [](M x, M y) -> M {return y;};
auto fp = [](M x, ll y) -> M {return x * y;};
X ex = 0;
M em = INF;
LazySegmentTree<X, M> seg(a, fx, fa, fm, fp, ex, em);
*/

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