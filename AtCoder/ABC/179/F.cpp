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

// Range Minimum Query and Range Update Query
class LazySegmentTree{
public:
    int n;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;

    LazySegmentTree(vector<ll> v){
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, INF);
        lazyFlag.resize(2*n-1, false);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void eval(int k, int l, int r){
        if(lazyFlag[k]){
            node[k] = lazy[k];

            if(r - l > 1){
                lazy[2*k+1] = lazy[2*k+2] = lazy[k];
                lazyFlag[2*k+1] = lazyFlag[2*k+2] = true;
            }

            lazyFlag[k] = false;
        }
    }

    void update(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;

        eval(k, l, r);

        if(b <= l || r <= a) return ;

        if(a <= l && r <= b){
            lazy[k] = x;
            lazyFlag[k] = true;
            eval(k, l, r);
        }
        else{
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

    ll find(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        
        eval(k, l, r);
        
        if(b <= l || r <= a) return INF;

        if(a <= l && r <= b) return node[k];
        ll vl = find(a, b, 2*k+1, l, (l+r)/2);
        ll vr = find(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin>>n;
    int q; cin>>q;

    LazySegmentTree yseg(vector<ll>(n - 1, n - 2)), xseg(vector<ll>(n - 1, n - 2));
    int xmi = inf, ymi = inf;
    ll ans = (n - 2) * (n - 2);
    while(q--){
        int a, idx; cin>>a>>idx; idx--;
        if(a == 1){
            int cur = xseg.find(idx, idx + 1);
            ans -= cur;
            if(idx < xmi){
                yseg.update(0, cur + 1, idx - 1);
                xmi = idx;
            }
        }
        else{
            int cur = yseg.find(idx, idx + 1);
            ans -= cur;
            if(idx < ymi){
                xseg.update(0, cur + 1, idx - 1);
                ymi = idx;
            }
        }
    }

    cout << ans << endl;

    return 0;
}