#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

template <class T> inline T chmax(T &a, T &b) {a = max(a, b);}
template <class T> inline T chmin(T &a, T &b) {a = min(a, b);}

constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    ll sum = accumulate(a.begin(), a.end(), 0LL);

    vector<ll> ans(n);
    ans[0] = sum;
    for(int i=1; i<n; i+=2){
        ans[0] -= 2 * a[i];
    }

    for(int i=0; i<n-1; i++){
        ans[i+1] = 2 * a[i] - ans[i];
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }
}