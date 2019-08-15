#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    ll n, m; cin>>n>>m;
    vector<int> a(n+10);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<ll> sum(n+10, 0);
    for(int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + a[i-1];
    }

    map<int, ll> mod_sum;
    for(int i=0; i<=n; i++) {
        mod_sum[sum[i] % m]++;
    }

    ll ans=0;
    for(auto i : mod_sum){
        ans += (i.second*(i.second - 1)) / 2;
    }
    cout << ans << endl;
}