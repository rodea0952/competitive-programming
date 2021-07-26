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
using P = pair<ll, ll>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<ll> a(m), c(m);
    for(int i=0; i<m; i++){
        cin >> a[i] >> c[i];
    }

    ll g = n;
    for(int i=0; i<m; i++){
        g = __gcd(g, a[i]);
    }

    if(g != 1){
        cout << -1 << endl;
        return 0;
    }

    priority_queue<P, vector<P>, greater<P>> que;
    for(int i=0; i<m; i++){
        que.emplace(c[i], a[i]);
    }

    ll cur_compo = n;
    ll ans = 0;
    while(1 < cur_compo){
        ll cc, ca; tie(cc, ca) = que.top(); que.pop();
        ll nxt_compo = __gcd(cur_compo, ca);
        if(cur_compo == nxt_compo) continue;
        ans += cc * (cur_compo - nxt_compo);
        cur_compo = nxt_compo;
    }

    cout << ans << endl;

    return 0;
}