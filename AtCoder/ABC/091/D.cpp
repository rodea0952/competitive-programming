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
    vector<ll> a(n), b(n), c(n), d(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        c[i]=a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
        d[i]=b[i];
    }

    ll t=1; 
    vector<ll> bitcnt(30);
    for(int bit=0; bit<30; bit++){
        for(int i=0; i<n; i++){
            a[i]%=2*t;
            b[i]%=2*t;
        }

        sort(b.begin(), b.end());

        ll sum=0;
        for(int i=0; i<n; i++){
            sum+=(lower_bound(b.begin(), b.end(), 2*t-a[i])-lower_bound(b.begin(), b.end(), t-a[i]));
            sum+=(lower_bound(b.begin(), b.end(), 4*t-a[i])-lower_bound(b.begin(), b.end(), 3*t-a[i]));
        }
        bitcnt[bit]=sum;

        for(int i=0; i<n; i++){
            a[i]=c[i];
            b[i]=d[i];
        }
        t*=2;
    }

    ll ans=0, num=1;
    for(int bit=0; bit<30; bit++){
        if(bitcnt[bit]%2==1) ans+=num;
        num*=2;
    }
    cout << ans << endl;
}