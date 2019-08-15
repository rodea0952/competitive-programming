#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

ll f(ll x, ll y){
    ll a=min(x, y), b=max(x, y);
    if(a==0) return -b;
    return f(a, b%a)+2LL*a*(b/a);
}

int main(){
    ll n, x; cin>>n>>x;
    cout << n+f(x, n-x) << endl;
}