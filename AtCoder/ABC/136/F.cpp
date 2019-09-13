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

constexpr int MOD = 998244353;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct SegmentTree{
private:
    int n;
    vector<int> node;

public:
    SegmentTree(vector<int> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    // Range Sum Query
    void add(int k, int val){
        k += (n - 1);
        node[k] += val;

        while(0 < k){
            k = (k - 1) / 2;
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    int getsum(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];

        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);

        return vl + vr;
    }
};

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b/2) % MOD;
        return (d * d) % MOD;
    }
    else{
        return (a * modpow(a, b-1)) % MOD;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<P> points;
    vector<int> Y;
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        points.emplace_back(x, y);
        Y.emplace_back(y);
    }

    sort(points.begin(), points.end());
    sort(Y.begin(), Y.end());

    map<int, int> y2index;
    for(int i=0; i<n; i++){
        y2index[Y[i]] = i;
    }

    vector<ll> A(n, 0);
    vector<ll> B(n, 0);
    vector<ll> C(n, 0);
    vector<ll> D(n, 0);

    SegmentTree pseg(vector<int>(n, 0));
    SegmentTree nseg(vector<int>(n, 1));

    for(int i=0; i<n; i++){
        int x, y;
        tie(x, y) = points[i];

        int index = y2index[y];

        nseg.add(index, -1);
        pseg.add(index, 1);

        B[i] = nseg.getsum(index + 1, n);
        D[i] = nseg.getsum(0, index);
        A[i] = pseg.getsum(index + 1, n);
        C[i] = pseg.getsum(0, index);
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += modpow(2, n-1);
        ans %= MOD;
        ll num1 = (((modpow(2, A[i]) - 1) * (modpow(2, D[i]) - 1) % MOD) * ((modpow(2, B[i]) * modpow(2, C[i])) % MOD)) % MOD;
        ll num2 = (((modpow(2, B[i]) - 1) * (modpow(2, C[i]) - 1) % MOD) * ((modpow(2, A[i]) * modpow(2, D[i])) % MOD)) % MOD;

        ans += ((num1 + num2) % MOD) - (((modpow(2, A[i]) - 1) * (modpow(2, B[i]) - 1) % MOD) * ((modpow(2, C[i]) - 1) * (modpow(2, D[i]) - 1) % MOD)) % MOD + MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}