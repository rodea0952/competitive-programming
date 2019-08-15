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
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    vector<ll> sum(n+10, 0);
    for(int i=0; i<n; i++){
        sum[i+1]=sum[i]+a[i];
    }

    int id;
    for(int i=n; i>1; i--){
        if(a[i-1]<=2LL*sum[i-1]) id=i;
        else break;
    }
    cout << n-id+2 << endl;
}