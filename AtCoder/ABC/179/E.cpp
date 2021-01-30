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

    ll n, x, m; cin>>n>>x>>m;

    vector<int> num2idx(m, -1);
    int idx = 0;
    vector<ll> v;
    while(num2idx[x] == -1){
        num2idx[x] = idx++;
        v.emplace_back(x);
        x = x * x % m;
    }

    ll ans = 0;
    if(n <= v.size()){
        for(int i=0; i<n; i++) ans += v[i];
        cout << ans << endl;
        return 0;
    }

    n -= v.size();
    ans = accumulate(all(v), 0LL);

    vector<int> cycle;
    for(int i=num2idx[x]; i<v.size(); i++) cycle.emplace_back(v[i]);

    int sz = cycle.size();
    vector<ll> sum(sz + 1, 0);
    for(int i=0; i<sz; i++) sum[i + 1] = sum[i] + cycle[i];

    ll cnt = n / sz, rem = n % sz;
    ans += cnt * sum[sz] + sum[rem];

    cout << ans << endl;

    return 0;
}