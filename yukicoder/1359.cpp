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

ll modpow(ll a, ll b, ll m){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b / 2, m) % m;
        return (d * d) % m;
    }
    else{
        return (a * modpow(a, b - 1, m)) % m;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k, m; cin>>n>>k>>m;
    vector<int> p(n), e(n), a(n), h(n);
    for(int i=0; i<n; i++) cin>>p[i];
    for(int i=0; i<n; i++) cin>>e[i];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>h[i];

    sort(all(p));
    sort(all(e));
    sort(all(a));
    sort(all(h));

    vector<int> d(n);
    for(int i=0; i<n; i++){
        vector<int> v;
        v.emplace_back(p[i]);
        v.emplace_back(e[i]);
        v.emplace_back(a[i]);
        v.emplace_back(h[i]);
        sort(all(v));
        d[i] = v[3] - v[0];
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += modpow(d[i], k, m);
        ans %= m;
    }

    cout << ans << endl;

    return 0;
}