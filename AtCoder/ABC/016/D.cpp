#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

bool intersection(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy){
    ll ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
    ll tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
    ll tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
    ll td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);

    return ta*tb<0 && tc*td<0;
}

int main(){
    int ax, ay, bx, by; cin>>ax>>ay>>bx>>by;
    int n; cin>>n;
    int x[n], y[n];
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    int ans=0;
    for(int i=0; i<n; i++){
        ans+=intersection(ax, ay, bx, by, x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
    }
    cout << ans/2+1 << endl;
}