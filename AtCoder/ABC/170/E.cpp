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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q; cin>>n>>q;
    vector<set<P>> kinder(200000);
    vector<int> infant(n, -1);
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
        b[i]--;
        kinder[b[i]].emplace(-a[i], i);
        infant[i] = b[i];
    }

    SegmentTree seg(vector<ll>(200000, INF));
    for(int i=0; i<200000; i++){
        if(kinder[i].size()){
            auto itr = kinder[i].begin();
            int cma = -(*itr).first;
            seg.update(i, cma);
        }
    }

    for(int i=0; i<q; i++){
        int idx, nxt; cin>>idx>>nxt;
        idx--, nxt--;
        int pre = infant[idx];
        infant[idx] = nxt;

        kinder[pre].erase(P(-a[idx], idx));
        if(kinder[pre].size()){
            auto itr = kinder[pre].begin();
            int cma = -(*itr).first;
            if(seg.getmin(pre, pre + 1) > cma){
                seg.update(pre, cma);
            }
        }
        else{
            seg.update(pre, INF);
        }

        kinder[nxt].emplace(-a[idx], idx);
        if(seg.getmin(nxt, nxt + 1) < a[idx] || seg.getmin(nxt, nxt + 1) == INF){
            seg.update(nxt, a[idx]);
        }
        
        cout << seg.getmin(0, 200000) << endl;
    }

    return 0;
}