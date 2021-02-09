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

template<typename T>
struct SegmentTree{
private:
    using Func = function<T(T, T)>;
    int n;
    vector<T> node;
    Func func;
    T init_v;

public:
    SegmentTree(vector<T> v, Func _func, T _init_v){
        func = _func, init_v = _init_v;
        int sz = v.size();
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2 * n, init_v);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = func(node[i*2+1], node[i*2+2]);
    }

    void update(int idx, T val){
        idx += n - 1;
        node[idx] = val;
        while(idx > 0){
            idx = (idx - 1) / 2;
            node[idx] = func(node[idx*2+1], node[idx*2+2]);
        }
    }

    T query(int a, int b, int k = 0, int l = 0, int r = -1){
        if (r < 0) r = n;
        if (r <= a || b <= l) return init_v;
        if (a <= l && r <= b) return node[k];
        T lv = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T rv = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return func(lv, rv);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q; cin>>n>>q;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    SegmentTree<ll> seg(a, [](const auto x, const auto y){return x ^ y;}, 0);

    while(q--){
        int op, x, y; cin>>op>>x>>y;
        x--;
        if(op == 1){
            ll cur = seg.query(x, x + 1);
            seg.update(x, cur ^ y);
        }
        else{
            cout << seg.query(x, y) << endl;
        }
    }

    return 0;
}