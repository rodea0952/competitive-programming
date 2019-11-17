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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> d(n);
    for(int i=0; i<n; i++) cin>>d[i];
    sort(d.begin(), d.end());

    vector<ll> half_cnt(n, 0);
    for(int i=0; i<n; i++){
        int dist = upper_bound(d.begin(), d.end(), d[i] / 2) - d.begin();
        half_cnt[i] = dist;
    }

    vector<ll> sum(n+1, 0);
    for(int i=0; i<n; i++){
        sum[i+1] = sum[i] + half_cnt[i];
    }

    ll ans = 0;
    // third difficulty
    for(int i=2; i<n-1; i++){
        ll dif4 = d.end() - lower_bound(d.begin(), d.end(), d[i] * 2);
        ll dif12 = upper_bound(d.begin(), d.end(), d[i] / 2) - d.begin();
        dif12 = sum[dif12];

        ans += dif12 * dif4;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}