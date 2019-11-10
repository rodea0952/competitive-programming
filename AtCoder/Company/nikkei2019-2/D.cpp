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

// Range Minumum Query
class SegmentTree{
public:
    int N;
    vector<ll> node;

    SegmentTree(vector<ll> v){
        int sz = v.size();
        N = 1; while(N < sz) N *= 2;
        node.resize(2*N-1, INF);
        for(int i=0; i<sz; i++) node[i+N-1] = v[i];
        for(int i=N-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, ll val){
        x += (N - 1);
        node[x] = val;
        while(0 < x){
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    ll getmin(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = N;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        
        return min(vl, vr);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    SegmentTree seg(vector<ll>(n, INF));
    seg.update(0, 0);

    vector<T> v;
    for(int i=0; i<m; i++){
        int l, r, c; cin>>l>>r>>c;
        v.emplace_back(l, r, c);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<m; i++){
        int l, r, c;
        tie(l, r, c) = v[i];
        l--, r--;
        ll val = seg.getmin(l, r);
        val += c;
        if(val < seg.node[(seg.N-1)+r]){
            seg.update(r, val);
        }
    }

    cout << (seg.node[(seg.N-1)+(n-1)] == INF ? -1 : seg.node[(seg.N-1)+(n-1)]) << endl;

    return 0;
}