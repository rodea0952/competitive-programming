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

    ll k, n, m; cin>>k>>n>>m;
    vector<ll> a(k);
    for(int i=0; i<k; i++) cin>>a[i];

    auto check = [&](ll x) -> bool {
        ll lb = 0, ub = 0;
        for(int i=0; i<k; i++){
            lb += (m * a[i] - x + n - 1) / n;
            ub += (m * a[i] + x) / n;
        }
        return (lb <= m && m <= ub);
    };

    ll ng = -1, ok = INF + 10;
    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    vector<pair<ll, ll>> b(k);
    ll rest = m;
    for(int i=0; i<k; i++){
        ll lb = (m * a[i] - ok + n - 1) / n, ub = (m * a[i] + ok) / n;
        b[i] = P(lb, ub);
        rest -= lb;
    }

    for(int i=0; i<k; i++){
        if(0 < rest){
            ll gap = b[i].second - b[i].first;
            b[i].first += min(rest, gap);
            rest -= min(rest, gap);
        }
    }

    for(int i=0; i<k; i++){
        cout << b[i].first << " \n"[i == k - 1];
    }

    return 0;
}