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
    vector<ll> v;
    ll num = n;
    for(ll i=2; i*i<=n; i++){
        while(num % i == 0){
            num /= i;
            v.emplace_back(i);
        }
    }

    if(num != 1){
        v.emplace_back(num);
    }

    return v;
}

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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> pcnt(1000010, 0);
    for(int i=0; i<n; i++){
        auto v = prime_factorization(a[i]);

        vector<P> cur;
        for(int j=0; j<v.size(); j++){
            int num = v[j];
            int cnt = 0;
            while(j < v.size() && num == v[j]){
                cnt++, j++;
            }
            j--;
            cur.emplace_back(num, cnt);
        }

        for(auto j:cur){
            chmax(pcnt[j.first], j.second);
        }
    }

    ll base = 1;
    for(int i=1; i<=1000000; i++){
        if(pcnt[i] != 0){
            base *= modpow(i, pcnt[i]);
            base %= MOD;
        }
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += base * modpow(a[i], MOD - 2);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}