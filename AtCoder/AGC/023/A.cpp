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
    map<ll, ll> mp;
    mp[0]=1;
    ll sum=0;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        sum+=a;
        mp[sum]++;
    }

    ll ans=0;
    for(auto x : mp){
        if(x.second>1) ans+=(x.second*(x.second-1)/2);
    }
    cout << ans << endl;
}