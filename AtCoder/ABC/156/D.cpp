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

    ll n, a, b; cin>>n>>a>>b;

    ll ans = modpow(2, n) - 1;

    ll nCa = 1;
    for(int i=0; i<a; i++){
        nCa *= (n - i);
        nCa %= MOD;
    }

    for(int i=a; i>=1; i--){
        nCa *= modpow(i, MOD - 2);
        nCa %= MOD;
    }

    ll nCb = 1;
    for(int i=0; i<b; i++){
        nCb *= (n - i);
        nCb %= MOD;
    }

    for(int i=b; i>=1; i--){
        nCb *= modpow(i, MOD - 2);
        nCb %= MOD;
    }

    ans -= nCa;
    ans += MOD;
    ans -= nCb;
    ans += MOD;

    cout << ans % MOD << endl;

    return 0;
}
