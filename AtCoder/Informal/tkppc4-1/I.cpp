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

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> low(n), high(n);
    for(int i=0; i<n; i++){
        int low_cnt = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        low[i] = low_cnt;
        int high_cnt = b.end() - upper_bound(b.begin(), b.end(), a[i]);
        high[i] = high_cnt;
    }

    vector<ll> sumh(n+1, 0);
    for(int i=0; i<n; i++){
        sumh[i+1] = sumh[i] + high[i];
    }

    // P
    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += low[i] * (sumh[n] - sumh[i+1]);
        ans %= MOD;
    }

    cout << ans << endl;
}