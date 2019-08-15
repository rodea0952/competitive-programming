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
    vector<int> a(3*n);
    for(int i=0; i<3*n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll ans=0;
    for(int i=3*n-2; i>=n; i-=2) ans+=a[i];
    cout << ans << endl;
}