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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

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

    int n; cin>>n;
    string s; cin>>s;
    seg.build(vector<int>(n, 0));

    for(int i=0; i<n; i++){
        seg.set_val(i, 1 << (s[i] - 'a'));
    }

    int q; cin>>q;
    while(q--){
        int ty; cin>>ty;
        if(ty == 1){
            int i; cin>>i;
            char c; cin>>c;
            i--;
            seg.set_val(i, 1 << (c - 'a'));
        }
        else{
            int l, r; cin>>l>>r;
            l--, r--;
            int ans = __builtin_popcount(seg.query(l, r + 1));
            cout << ans << endl;
        }
    }

    return 0;
}