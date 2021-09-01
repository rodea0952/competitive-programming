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

    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    ll ans = 0;
    if(accumulate(all(a), 0LL) <= k){
        for(int i=0; i<n; i++){
            ans += a[i] * (a[i] + 1) / 2;
        }
        cout << ans << endl;
        return 0;
    }

    ll ok = 0, ng = INF;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        ll cnt = 0;
        for(int i=0; i<n; i++){
            cnt += max(0LL, (a[i] - mid) + 1);
        }
        (k <= cnt ? ok : ng) = mid;
    }

    ll cnt = 0;
    for(int i=0; i<n; i++){
        if(ok > a[i]) continue;
        ans += a[i] * (a[i] + 1) / 2 - ok * (ok - 1) / 2;
        cnt += a[i] - ok + 1;
    }

    ans -= ok * (cnt - k);
    
    cout << ans << endl;

    return 0;
}