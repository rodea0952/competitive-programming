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

vector<vector<ll>> mul(vector<vector<ll>> &A, vector<vector<ll>> &B){
    vector<vector<ll>> C(A.size(), vector<ll>(B.size()));

    for(int i=0; i<A.size(); i++){
        for(int k=0; k<B.size(); k++){
            for(int j=0; j<B[0].size(); j++){
                (C[i][j] += (A[i][k] * B[k][j]) % MOD) %= MOD;
            }
        }
    }
    
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> A, ll n){
    vector<vector<ll>> B(A.size(), vector<ll>(A.size()));

    for(int i=0; i<A.size(); i++){
        B[i][i] = 1;
    }

    while(n > 0){
        if(n & 1LL) B = mul(B, A);
        A = mul(A, A);
        n >>= 1LL;
    }

    return B;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m, k, p, q; cin>>n>>m>>k>>p>>q;
    vector<ll> b(n);
    for(int i=0; i<n; i++) cin>>b[i];

    vector<vector<ll>> A(2, vector<ll>(2));
    ll num1 = p * modpow(q, MOD - 2) % MOD;
    ll num2 = (1 - num1 + MOD) % MOD;
    A[0][0] = num2; A[0][1] = num1;
    A[1][0] = num1; A[1][1] = num2;
    A = pow(A, k);

    ll ans = 0;
    for(int i=0; i<m; i++){
        ans += b[i] * A[0][0] % MOD;
        ans %= MOD;
    }

    for(int i=m; i<n; i++){
        ans += b[i] * A[0][1] % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}