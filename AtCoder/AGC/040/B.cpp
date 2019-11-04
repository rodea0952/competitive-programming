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

struct SegmentTreeMin{
private:
    int n;
    vector<int> node;

public:
    // Range Minumum Query
    SegmentTreeMin(vector<int> v){
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val){
        x += (n - 1);
        node[x] = val;
        while(0 < x){
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    int getmin(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return inf;
        if(a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        
        return min(vl, vr);
    }
};

struct SegmentTreeMax{
private:
    int n;
    vector<int> node;

public:
    // Range Maximum Query
    SegmentTreeMax(vector<int> v){
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val){
        x += (n - 1);
        node[x] = val;
        while(0 < x){
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    int getmax(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];

        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        
        return max(vl, vr);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<P> lr(n);
    for(int i=0; i<n; i++){
        int l, r; cin>>l>>r;
        lr[i] = P(l, r);
    }

    sort(lr.begin(), lr.end());

    vector<int> l(n), r(n);
    for(int i=0; i<n; i++){
        l[i] = lr[i].first;
        r[i] = lr[i].second;
    }

    SegmentTreeMax segl(l);
    SegmentTreeMin segr(r);

    ll ans = 0;
    for(int i=1; i<n; i++){
        int headmax = segl.getmax(0, i);
        int headmin = segr.getmin(0, i);
        int tailmax = segl.getmax(i, n);
        int tailmin = segr.getmin(i, n);

        chmax(ans, (ll)(max(0, headmin - headmax + 1) + max(0, tailmin - tailmax + 1)));
    }

    for(int i=0; i<n; i++){
        int cur = r[i] - l[i] + 1;
        int lmax = max(segl.getmax(0, i), segl.getmax(i + 1, n));
        int rmin = min(segr.getmin(0, i), segr.getmin(i + 1, n));

        chmax(ans, (ll)(cur + max(0, rmin - lmax + 1)));
    }

    cout << ans << endl;

    return 0;
}
