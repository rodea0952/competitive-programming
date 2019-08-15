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

    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;
    for(int i=0; i<n; i++){
        if(i < k) ans += a[i];
        else ans += 2 * a[i];
    }

    cout << ans << endl;
}