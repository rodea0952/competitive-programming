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

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b/2) % MOD;
        return (d * d) % MOD;
    }
    else{
        return (a * modpow(a, b-1)) % MOD;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> a(n), cnt(n, 0);
    for(int i=0; i<n; i++) cin>>a[i];

    ll amax = *max_element(a.begin(), a.end());

    for(int i=0; i<n; i++) cnt[a[i]]++;

    if(cnt[0] != 1){
        cout << 0 << endl;
        return 0;
    }

    if(a[0] != 0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for(int i=1; i<=amax; i++){
        ll base = (modpow(2, cnt[i-1]) - 1 + MOD) % MOD;
        ll cur = 1;

        cur *= modpow(base, cnt[i]);
        cur %= MOD;

        ll sum = (modpow(2, (cnt[i]) * (cnt[i] - 1) / 2));

        cur *= sum;
        cur %= MOD;

        ans *= cur;
        ans %= MOD;
    }

    cout << ans << endl;
}
