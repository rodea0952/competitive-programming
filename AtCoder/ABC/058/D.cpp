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
    ll n, m; cin>>n>>m;
    vector<ll> x(n), y(m);
    for(int i=0; i<n; i++) cin>>x[i];
    for(int i=0; i<m; i++) cin>>y[i];

    vector<ll> num1(n), num2(m);
    for(ll i=0; i<n-1; i++){
        num1[i]=(i+1)*(n-i-1);
    }
    for(ll i=0; i<m-1; i++){
        num2[i]=(i+1)*(m-i-1);
    }

    ll ans1=0, ans2=0;
    for(int i=0; i<n-1; i++){
        ans1+=(x[i+1]-x[i])*num1[i];
        ans1%=MOD;
    }
    for(int i=0; i<m-1; i++){
        ans2+=(y[i+1]-y[i])*num2[i];
        ans2%=MOD;
    }
    cout << (ans1*ans2)%MOD << endl;
}