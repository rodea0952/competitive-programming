#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<ll> sum(410);
vector<vector<ll>> dp(410, vector<ll>(410, -1));

// [l, r)
ll solve(int l, int r){
    if(0 <= dp[l][r]) return dp[l][r];
    if(r - l == 1) return dp[l][r] = 0;

    ll val = INF;
    for(int i=l+1; i<r; i++){
        // [l, r) -> [l, i) and [i, r)
        ll cost = sum[r] - sum[l];
        chmin(val, solve(l, i) + solve(i, r) + cost);
    }

    return dp[l][r] = val;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum[i+1] = sum[i] + a[i];
    }

    cout << solve(0, n) << endl;
}