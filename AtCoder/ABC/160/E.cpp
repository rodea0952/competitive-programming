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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y, a, b, c; cin>>x>>y>>a>>b>>c;
    vector<int> p(a), q(b), r(c);
    for(int i=0; i<a; i++) cin>>p[i];
    for(int i=0; i<b; i++) cin>>q[i];
    for(int i=0; i<c; i++) cin>>r[i];

    sort(all(p), greater<int>());
    sort(all(q), greater<int>());

    vector<int> v;
    for(int i=0; i<x; i++) v.emplace_back(p[i]);
    for(int i=0; i<y; i++) v.emplace_back(q[i]);
    for(int i=0; i<c; i++) v.emplace_back(r[i]);

    sort(all(v), greater<int>());

    ll ans = 0;
    for(int i=0; i<x+y; i++) ans += v[i];

    cout << ans << endl;

    return 0;
}