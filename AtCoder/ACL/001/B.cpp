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

vector<ll> prime_factorization(ll n){
    vector<ll> res;
    ll num = n;
    for(ll i=2; i*i<=n; i++){
        if(num % i != 0) continue;

        ll cur = 1;
        while(num % i == 0){
            num /= i;
            cur *= i;
        }
        res.emplace_back(cur);
    }

    if(num != 1){
        res.emplace_back(num);
    }

    return res;
}

// {g, x, y} : a x + b y = g
tuple<ll, ll, ll> extgcd(ll a, ll b){
    if(b == 0) return {a, 1, 0};
    ll g, x, y; tie(g, x, y) = extgcd(b, a % b);
    return {g, y, x - a / b * y};
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    n *= 2;

    auto prime = prime_factorization(n);
    int sz = prime.size();
    ll ans = n - 1;
    for(int bit=0; bit<(1<<sz); bit++){
        ll a = 1;
        for(int i=0; i<sz; i++){
            if(bit & (1 << i)){
                a *= prime[i];
            }
        }
        ll b = n / a;
        ll g, x, y; tie(g, x, y) = extgcd(a, b);
        ll cur = (a * -x) % n;
        if(cur <= 0) cur += n;
        chmin(ans, cur);
    }

    cout << ans << endl;

    return 0;
}