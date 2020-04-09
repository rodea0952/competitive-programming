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
using P = pair<int, ll>;
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
    ll A, B; cin>>A>>B;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(all(a));

    if(A == 1){
        for(int i=0; i<n; i++){
            cout << a[i] << endl;
        }
        return 0;
    }

    while(B > 0){
        sort(all(a));
        if(a[0] * A >= a.back()) break;
        a[0] *= A;
        B--;
    }

    sort(all(a));

    ll cnt = B / n;
    ll rem = B % n;
    for(int i=0; i<rem; i++){
        a[i] %= MOD;
        a[i] *= modpow(A, cnt + 1);
        a[i] %= MOD;
    }
    for(int i=rem; i<n; i++){
        a[i] %= MOD;
        a[i] *= modpow(A, cnt);
        a[i] %= MOD;
    }

    vector<ll> ans;
    for(int i=rem; i<n; i++) ans.emplace_back(a[i]);
    for(int i=0; i<rem; i++) ans.emplace_back(a[i]);

    for(int i=0; i<n; i++){
        cout << ans[i] << endl;
    }
    
    return 0;
}