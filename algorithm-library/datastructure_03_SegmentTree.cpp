// Range Minumum Query
class SegmentTree{
public:
    int n;
    vector<ll> node;

    SegmentTree(vector<ll> v){
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, ll val){
        x += (n - 1);
        node[x] = val;
        while(0 < x){
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    ll getmin(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        
        return min(vl, vr);
    }
};

// Range Sum Query
class SegmentTree{
public:
    int n;
    vector<ll> node;

    SegmentTree(vector<ll> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void add(int x, ll val){
        x += (n - 1);
        node[x] += val;
        while(0 < x){
            x = (x - 1) / 2;
            node[x] = node[2*x+1] + node[2*x+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];

        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);

        return vl + vr;
    }
};

// refer to http://beet-aizu.hatenablog.com/entry/2019/03/12/171221
template <typename T, typename E, typename F, typename G>
struct SegmentTree{
    int n;
    F f;
    G g;
    T ti;
    vector<T> dat;
    SegmentTree(){};
    SegmentTree(F f, G g, T ti) : f(f), g(g), ti(ti){}

    void init(int n_){    
        n = 1;
        while(n < n_) n <<= 1;
        dat.assign(n << 1, ti);
    }

    void build(const vector<T> &v){
        int sz = v.size();
        init(sz);
        for(int i=0; i<sz; i++) dat[n + i] = v[i];
        for(int i=n-1; i>=0; i--) dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }

    void set_val(int k, T x){
        k += n;
        dat[k] = g(dat[k], x);
        while(k >>= 1) dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);    
    }

    T query(int a,int b){
        T vl = ti, vr = ti;
        for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
            if(l & 1) vl = f(vl, dat[l++]);
            if(r & 1) vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }
};

using T = int;
using E = int;
auto f = [](T a, T b){
    return a | b;
};
auto g = [](T a, E b){
    return b;
};
T ti = 0;
SegmentTree<T, E, decltype(f), decltype(g)> seg(f, g, ti);