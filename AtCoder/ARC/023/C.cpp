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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    P lb = P(0, 0), ub = P(0, 0);
    ll ans = 1;
    for(int i=0; i+1<n; i++){
        if(a[i] != -1) lb = P(a[i], i);

        if(a[i] == -1 && a[i+1] != -1) ub = P(a[i+1], i+1);

        if(lb != P(0, 0) && ub != P(0, 0)){
            int gap = ub.first - lb.first;
            int len = ub.second - lb.second - 1;

            int N = (gap + len), K = len;
            for(int j=0; j<K; j++){
                ans *= (N - j);
                ans %= MOD;
                ans *= modpow(j + 1, MOD - 2);
                ans %= MOD;
            }

            lb = P(0, 0), ub = P(0, 0);
        }
    }

    cout << ans << endl;

    return 0;
}