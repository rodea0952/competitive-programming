#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    ll a, b, c; cin>>a>>b>>c;
    if(a%2==0 || b%2==0 || c%2==0) cout << 0 << endl;
    else cout << min({a*b, b*c, c*a}) << endl;
}