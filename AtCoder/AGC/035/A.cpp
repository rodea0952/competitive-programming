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

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    string ans = "No";

    // 0, 0, 0, ...
    if(a[n-1] == 0){
        ans = "Yes";
    }

    if(n % 3 == 0){
        // 0, 0, X, X, X, X
        if(a[0] == a[n/3-1] && a[0] == 0 && a[n/3] == a[n-1]){
            ans = "Yes";
        }

        // X, X, Y, Y, Z, Z and X ^ Y = Z
        if(a[0] == a[n/3-1] && a[n/3] == a[n*2/3-1] &&
            a[n*2/3] == a[n-1] && (a[0] ^ a[n/3]) == a[n*2/3]){
            ans = "Yes";
        }
    }

    cout << ans << endl;
}