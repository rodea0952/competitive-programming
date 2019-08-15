#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n, k; cin>>n>>k;
    vector<ll> sum(n+10, 0); 
    for(int i=0; i<n; i++) {
        int a; cin>>a;
        sum[i+1] = sum[i] + a;
    }

    ll ans=0;
    for(int i=0; i<n-k+1; i++){
        ans += sum[k+i] - sum[i];
    }
    cout << ans << endl;
}