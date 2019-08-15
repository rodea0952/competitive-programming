#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    ll n, h; cin>>n>>h;
    ll a, b, c, d, e; cin>>a>>b>>c>>d>>e;

    ll ans=INF;
    for(ll x=0; x<=n; x++){
        ll y = ((double)((n-x)*e - h - b*x) / (d + e)) + 1.0;
        if(y < 0) y = 0;
        ans = min(ans, a*x + c*y);
    }
    cout << ans << endl;
}