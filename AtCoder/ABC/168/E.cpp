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
using P = pair<ll, ll>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b / 2) % MOD;
        return (d * d) % MOD;
    }
    else{
        return (a * modpow(a, b - 1)) % MOD;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    ll abzero = 0, azero = 0, bzero = 0;
    map<P, ll> cnt;
    for(int i=0; i<n; i++){
        ll a, b; cin>>a>>b;

        if(a == 0 && b == 0){
            abzero++;
        }
        else if(a == 0){
            azero++;
        }
        else if(b == 0){
            bzero++;
        }
        else{
            ll g = __gcd(abs(a), abs(b));
            a /= g, b /= g;

            if(0 > b) a *= -1, b *= -1;

            cnt[P(a, b)]++;
        }
    }

    set<P> used;
    ll ans = modpow(2, azero) + modpow(2, bzero) - 1;
    ans %= MOD;
    for(auto i : cnt){
        ll a = i.first.first, b = i.first.second;
        ll c = i.second;

        used.emplace(a, b);

        if(a < 0) a = -a;
        else b = -b;

        ll sum = 0;
        if(!used.count(P(b, a))){
            used.emplace(b, a);
            sum += modpow(2, c) + modpow(2, cnt[P(b, a)]) - 1;
            sum %= MOD;
            ans *= sum;
            ans %= MOD;
        }
    }

    ans += abzero;
    ans %= MOD;
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << endl;

    return 0;
}