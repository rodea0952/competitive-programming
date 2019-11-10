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

constexpr int MOD = 998244353;
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
    vector<int> d(n);
    vector<ll> cnt(n, 0);
    for(int i=0; i<n; i++){
        cin>>d[i];
        cnt[d[i]]++;
    }

    int dmax = *max_element(d.begin(), d.end());

    if(d[0] != 0){
        cout << 0 << endl;
        return 0;
    }

    if(1 < cnt[0]){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for(int i=1; i<=dmax; i++){
        int pre = i - 1;
        int cur = i;
        ans *= modpow(cnt[pre], cnt[cur]);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
