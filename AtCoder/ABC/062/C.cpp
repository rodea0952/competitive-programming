#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

ll calc1(ll h, ll w){
    ll ans=INF;
    for(ll i=0; i<=h; i++){
        ll S1=i*w;
        ll W=w/2;
        ll S2=(h-i)*W;
        ll S3=(h-i)*(w-W);
        ll MAX=max({S1, S2, S3}), MIN=min({S1, S2, S3});
        ans=min(ans, MAX-MIN);
    }
    return ans;
}

ll calc2(ll h, ll w){
    ll ans=INF;
    for(ll i=0; i<=h; i++){
        ll S1=i*w;
        ll H=(h-i)/2;
        ll S2=H*w;
        ll S3=(h-i-H)*w;
        ll MAX=max({S1, S2, S3}), MIN=min({S1, S2, S3});
        ans=min(ans, MAX-MIN);
    }
    return ans;
}

int main(){
    ll h, w; cin>>h>>w;
    cout << min({calc1(h, w), calc1(w, h), calc2(h, w), calc2(w, h)}) << endl;
}