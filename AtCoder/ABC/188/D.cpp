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

    ll n, C; cin>>n>>C;
    vector<pair<ll, ll>> v;
    for(int i=0; i<n; i++){
        ll a, b, c; cin>>a>>b>>c;
        v.emplace_back(a, c);
        v.emplace_back(b + 1, -c);
    }

    sort(all(v));

    ll ans = 0, scost = 0, pre = 0;
    for(auto i : v){
        ll cur, cost; tie(cur, cost) = i;
        ans += min(C, scost) * (cur - pre);
        pre = cur;
        scost += cost;
    }

    cout << ans << endl;

    return 0;
}