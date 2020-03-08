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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// Range Maximum Query
class SegmentTree{
public:
    int n;
    vector<ll> node;

    SegmentTree(vector<ll> v){
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void update(int x, ll val){
        x += (n - 1);
        node[x] = val;
        while(0 < x){
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    ll getmax(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];

        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        
        return max(vl, vr);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<P> xd(n);
    for(int i=0; i<n; i++) cin>>xd[i].first>>xd[i].second;
    sort(xd.begin(), xd.end());

    vector<ll> x(n), d(n);
    for(int i=0; i<n; i++){
        x[i] = xd[i].first;
        d[i] = xd[i].second;
    }

    // r[i] := ロボット i を起動した際に連動して起動するロボットの最大のインデックス
    vector<int> r(n);
    SegmentTree seg(vector<ll>(n+1, 0));
    for(int i=n-1; i>=0; i--){
        int toid = lower_bound(x.begin(), x.end(), x[i] + d[i]) - x.begin();
        // 届く範囲で最大の r を求める
        r[i] = max(i, r[seg.getmax(i, toid)]);
        seg.update(i, r[i]);
    }

    vector<ll> dp(n+1, 0);
    dp[n] = 1;
    for(int i=n-1; i>=0; i--){
        // dp[i+1] := i を起動させないとき
        // dp[r[i] + 1] := i を起動させるとき、r[i] + 1 番目のロボットは連動して起動しない
        dp[i] = dp[i+1] + dp[r[i] + 1];
        dp[i] %= MOD;
    }

    cout << dp[0] << endl;

    return 0;
}