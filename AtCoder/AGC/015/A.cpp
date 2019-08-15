#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    ll n, a, b; cin>>n>>a>>b;
    ll ans=(b-a)*(n-2)+1;
    cout << (ans>0 ? ans : 0) << endl;
}