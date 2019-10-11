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

using ll = unsigned long long;
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

    ll k, n; cin>>k>>n;
    vector<ll> a(n), d(n);
    for(int i=0; i<n; i++) cin>>a[i]>>d[i];

    ll ng = 0, ok = 1e12;
    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;

        ll sum = 0;
        for(int i=0; i<n; i++){
            if(mid < a[i]) continue;
            sum += (mid - a[i]) / d[i] + 1;
        }

        if(k <= sum) ok = mid;
        else ng = mid;
    }

    ll ans = 0, cnt = 0;
    for(int i=0; i<n; i++){
        if(ok < a[i]) continue;
        ll num = (ok - a[i]) / d[i] + 1;
        cnt += num;
        ans += num * (a[i] + a[i] + (num - 1) * d[i]) / 2;
    }

    ans -= ok * (cnt - k);

    cout << ans << endl;

    return 0;
}
