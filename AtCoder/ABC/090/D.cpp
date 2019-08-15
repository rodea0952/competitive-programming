#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    ll n, k; cin>>n>>k;

    if(k == 0){
        cout << n*n << endl;
        return 0;
    }

    ll ans=0;
    for(ll i=k+1; i<=n; i++){
        ans += (n / i) * (i - k);
        ans += max(0LL, (n % i) - k + 1LL);
    }
    cout << ans << endl;
}