#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, p; cin>>n>>p;
    bool o_exist=false;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        if(a%2 == 1) o_exist=true;
    }

    ll ans=1;
    for(int i=0; i<n; i++) ans*=2;
    if(o_exist) cout << ans/2 << endl;
    else cout << (p == 1 ? 0 : ans) << endl;
}