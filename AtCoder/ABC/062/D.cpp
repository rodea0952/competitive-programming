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
    vector<ll> a(3*n), headsum(3*n, 0), tailsum(3*n, 0);
    for(int i=0; i<3*n; i++) cin>>a[i];

    priority_queue<int, vector<int>, greater<int>> head;
    priority_queue<int> tail;

    headsum[0]=a[0];
    for(int i=0; i<n; i++){
        head.push(a[i]);
        if(i>0) headsum[i]=headsum[i-1]+a[i];
    }
    tailsum[3*n-1]=a[3*n-1];
    for(int i=3*n-1; i>=2*n; i--){
        tail.push(a[i]);
        if(i<3*n-1) tailsum[i]=tailsum[i+1]+a[i];
    }

    for(int i=n; i<=2*n; i++){
        head.push(a[i]);
        int hmin=head.top(); head.pop();
        headsum[i]=headsum[i-1]+a[i]-hmin;
    }
    for(int i=2*n-1; i>=n; i--){
        tail.push(a[i]);
        int tmax=tail.top(); tail.pop();
        tailsum[i]=tailsum[i+1]+a[i]-tmax;
    }

    ll ans=-INF;
    for(int i=n-1; i<=2*n-1; i++){
        ans=max(ans, headsum[i]-tailsum[i+1]);
    }
    cout << ans << endl;
}