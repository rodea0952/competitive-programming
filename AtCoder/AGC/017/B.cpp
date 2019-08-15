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
    ll n, a, b, c, d; cin>>n>>a>>b>>c>>d;
    for(ll i=0; i<n; i++){
        if(c*i-d*(n-i-1)<=b-a && b-a<=d*i-c*(n-i-1)){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}