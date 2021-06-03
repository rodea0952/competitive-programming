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

    int n; cin>>n;
    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    map<ll, int> acnt, bcnt;
    for(int i=0; i<n; i++){
        a[i] += i;
        b[i] += i;
        acnt[a[i]]++;
        bcnt[b[i]]++;
    }

    bool valid = true;
    for(auto i : acnt){
        if(i.second != bcnt[i.first]) valid = false;
    }

    if(!valid){
        cout << -1 << endl;
        return 0;
    }

    map<ll, vector<int>> aidx, bidx;
    for(int i=0; i<n; i++){
        aidx[a[i]].emplace_back(i);
        bidx[b[i]].emplace_back(i);
    }

    vector<int> v(n);
    for(auto i : aidx){
        for(int j=0; j<i.second.size(); j++){
            v[i.second[j]] = bidx[i.first][j];
        }
    }

    using X = ll;
    using M = ll;
    vector<X> base(n, 0);
    auto fx = [](X x, X y) -> X {return x + y;};
    auto fa = [](X x, M y) -> X {return x + y;};
    X ex = 0;
    SegmentTree<X, M> seg(base, fx, fa, ex);

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += seg.query(v[i], n);
        seg.update(v[i], 1);
    }

    cout << ans << endl;

    return 0;
}