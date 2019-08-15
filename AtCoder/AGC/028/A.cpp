#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x % y);
}

int main(){
    ll n, m; cin>>n>>m;
    string s, t; cin>>s>>t;
    
    ll ans=n*m/gcd(n, m);
    
    ll num=(ans/n)*(ans/m); 
    ll cntn=ans/n, cntm=ans/m;
    vector<char> stringn, stringm;
    for(ll i=0; i<n; i++){
        if((cntn*i)%num==0) stringn.push_back(s[i]);
    }
    for(ll i=0; i<m; i++){
        if((cntm*i)%num==0) stringm.push_back(t[i]);
    }

    bool f=true;
    for(int i=0; i<stringn.size(); i++){
        if(stringn[i]!=stringm[i]) f=false;
    }
    
    if(f) cout << ans << endl;
    else cout << -1 << endl;
}
