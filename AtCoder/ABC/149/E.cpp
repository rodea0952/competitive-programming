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
    ll m; cin>>m;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    ll ok = 0, ng = INF;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;

        ll sum = 0;
        // a[j] >= mid - a[i]
        for(int i=0; i<n; i++){
            int dist = lower_bound(a.begin(), a.end(), mid - a[i]) - a.begin();
            sum += (n - dist);
        }

        if(sum >= m) ok = mid;
        else ng = mid;
    }

    vector<ll> sum(n+1, 0);
    for(int i=0; i<n; i++){
        sum[i+1] = sum[i] + a[i];
    }

    ll num = 0, ans = 0;
    for(int i=0; i<n; i++){
        int dist = lower_bound(a.begin(), a.end(), ok - a[i]) - a.begin();
        num += (n - dist);
        ans += (sum[n] - sum[dist]) * 2;
    }

    ans -= (num - m) * ok;

    cout << ans << endl;

    return 0;
}