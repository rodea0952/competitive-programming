#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    ll n, a, b; cin>>n>>a>>b;
    vector<ll> x(n);
    for(int i=0; i<n; i++) cin>>x[i];

    vector<ll> d(n);
    for(int i=0; i<n-1; i++){
        d[i]=x[i+1]-x[i];
    }

    ll ans=0;
    for(int i=0; i<n-1; i++){
        if(d[i]*a<=b) ans+=d[i]*a;
        else ans+=b;
    }
    cout << ans << endl;
}