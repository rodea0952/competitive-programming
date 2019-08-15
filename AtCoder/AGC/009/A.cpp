#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];

    ll ans=0;
    for(int i=n-1; i>=0; i--){
        a[i]+=ans;
        ans+=((a[i]+b[i]-1)/b[i])*b[i]-a[i];
    }
    cout << ans << endl;
}