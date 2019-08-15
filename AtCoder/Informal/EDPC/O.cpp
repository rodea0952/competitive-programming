#pragma GCC optimize("O3")
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    vector<vector<ll>> dp(n+1, vector<ll>((1<<n), 0));
    dp[0][0] = 1;

    for(int bit=0; bit<(1<<n); bit++){
        int i = __builtin_popcount(bit);

        for(int j=0; j<n; j++){
            if(!(bit & (1<<j)) && a[i][j]){
                int nbit = bit | (1 << j);
                (dp[i+1][nbit] += dp[i][bit]) %= MOD;
            }
        }
    }

    cout << dp[n][(1<<n)-1] << endl;
}