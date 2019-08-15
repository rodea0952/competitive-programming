#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    for(int i=0; i<n; i++) cin>>c[i];

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    ll ans=0;
    for(int i=0; i<n; i++){
        ll sum=1;
        sum*=(lower_bound(a.begin(), a.end(), b[i])-a.begin());
        sum*=(n-(upper_bound(c.begin(), c.end(), b[i])-c.begin()));
        ans+=sum;
    }
    cout << ans << endl;
}