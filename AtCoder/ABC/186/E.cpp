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

// {g, x, y} : a x + b y = g
tuple<ll, ll, ll> extgcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};
    ll g, x, y; tie(g, x, y) = extgcd(b, a % b);
    return {g, y, x - a / b * y};
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        ll n, s, k; cin>>n>>s>>k;
        ll g, x, y; tie(g, x, y) = extgcd(k, n);
        if(s % g != 0){
            cout << -1 << endl;
        }
        else{
            n /= g, s /= g, k /= g;
            ll ans = ((-s * x) % n + n) % n;
            cout << ans << endl;
        }
    }

    return 0;
}