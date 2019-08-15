#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    ll q, h, s, d; cin>>q>>h>>s>>d;
    ll n; cin>>n;

    if(n == 1){
        cout << min({q*4, h*2, s}) << endl;
        return 0;
    }

    ll MIN=min({q*8, h*4, s*2, d});
    if(MIN != d){
        if(MIN == q*8) cout << 4*n*q << endl;
        else if(MIN == h*4) cout << 2*n*h << endl;
        else cout << s*n << endl;
    }
    else{
        ll MIN2=min({q*4, h*2, s});
        if(n%2 == 0) cout << n*d/2 << endl;
        else cout << (n-1)*d/2 + MIN2 << endl;
    }
}