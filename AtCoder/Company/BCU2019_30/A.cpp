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

    int n, p; cin>>n>>p;
    int ans = 0;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        if(0 <= p - a && ans == i){
            p -= a;
            ans++;
        }
    }

    cout << ans << endl;
}