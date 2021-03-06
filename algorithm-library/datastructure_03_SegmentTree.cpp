/*
Range Minumum Query
using X = ll;
using M = ll;
vector<X> a(n, INF);
auto fx = [](X x, X y) -> X {return min(x, y);};
auto fa = [](X x, M y) -> X {return y;};
X ex = INF;
SegmentTree<X, M> seg(a, fx, fa, ex);

Range Sum Query
using X = ll;
using M = ll;
vector<X> a(n, 0);
auto fx = [](X x, X y) -> X {return x + y;};
auto fa = [](X x, M y) -> X {return x + y;};
X ex = 0;
SegmentTree<X, M> seg(a, fx, fa, ex);
*/

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