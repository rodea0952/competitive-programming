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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// Range Add Query and Range Sum Query
class LazySegmentTree{
public:
    int n;
    vector<ll> node, lazy;

    LazySegmentTree(vector<ll> v){
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[2*i+1] + node[2*i+2];
    }

    void eval(int k, int l, int r){
        if(lazy[k] != 0){
            node[k] += lazy[k];

            if(r - l > 1){
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }

            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;

        eval(k, l, r);

        if(b <= l || r <= a) return ;

        if(a <= l && r <= b){
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else{
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;

        eval(k, l, r);
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, q; cin>>n>>q;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<char> c(q);
    vector<ll> x(q), y(q);
    for(int i=0; i<q; i++){
        cin>>c[i]>>x[i]>>y[i];
        if(c[i] == 'B') y[i]--; 
        x[i]--;
    }

    LazySegmentTree seg(vector<ll>(n, 0));

    vector<ll> b(n, 0);
    for(int i=q-1; i>=0; i--){
        if(c[i] == 'B'){
            seg.add(x[i], y[i] + 1, 1);
        }
        else{
            ll cur = seg.getsum(x[i], x[i] + 1);
            b[x[i]] += cur * y[i];
        }
    }

    for(int i=0; i<n; i++){
        ll cur = seg.getsum(i, i + 1);
        b[i] += cur * a[i];
    }

    for(int i=0; i<n; i++){
        cout << b[i] << " \n"[i == n - 1];
    }

    return 0;
}