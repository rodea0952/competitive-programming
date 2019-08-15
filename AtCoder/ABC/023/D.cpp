#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<ll> h(n), s(n);
    for(int i=0; i<n; i++) cin>>h[i]>>s[i];

    ll lb=0, ub=INF;
    ll ans=INF;
    while(ub-lb>1){
        ll height=(lb+ub)/2;
        //cout << "[" << lb << "," << ub << ") " << height << endl;

        bool height_small=false;
        vector<ll> need_time(n);
        for(int i=0; i<n; i++){
            if(height-h[i]<0) height_small=true;
            need_time[i]=(height-h[i])/s[i];
        }

        sort(need_time.begin(), need_time.end());

        for(int i=0; i<n; i++){
            if(need_time[i]<i) height_small=true;
        }

        if(height_small) lb=height;
        else{
            chmin(ans, height);
            ub=height;
        }
    }
    cout << ans << endl;
}