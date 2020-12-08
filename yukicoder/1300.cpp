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

constexpr int mod = 998244353;
constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    set<int> st;
    for(int i=0; i<n; i++) st.emplace(a[i]);

    map<int, int> num2idx;
    int idx = 0;
    for(auto i:st){
        num2idx[i] = idx++;
    }

    SegmentTree clseg(vector<ll>(n, 0)), slseg(vector<ll>(n, 0));
    vector<ll> cntl(n, 0), suml(n, 0);
    for(int i=0; i<n; i++){
        cntl[i] = clseg.getsum(num2idx[a[i]] + 1, n);
        suml[i] = slseg.getsum(num2idx[a[i]] + 1, n);
        clseg.add(num2idx[a[i]], 1);
        slseg.add(num2idx[a[i]], a[i]);
    }

    SegmentTree crseg(vector<ll>(n, 0)), srseg(vector<ll>(n, 0));
    vector<ll> cntr(n, 0), sumr(n, 0);
    for(int i=n-1; i>=0; i--){
        cntr[i] = crseg.getsum(0, num2idx[a[i]]);
        sumr[i] = srseg.getsum(0, num2idx[a[i]]);
        crseg.add(num2idx[a[i]], 1);
        srseg.add(num2idx[a[i]], a[i]);
    }

    ll ans = 0;
    for(int i=1; i+1<n; i++){
        ll L = (suml[i] % mod) * cntr[i] % mod;
        ll R = (sumr[i] % mod) * cntl[i] % mod;
        ll mid = a[i] * cntl[i] % mod * cntr[i] % mod;
        ans += (L + mid + R) % mod;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}