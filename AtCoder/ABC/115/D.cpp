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

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    ll n, x; cin>>n>>x;
    vector<ll> cntP(60, 0), l(60, 0);
    cntP[0]=1, l[0]=1;
    for(int i=1; i<=n; i++){
        cntP[i]=cntP[i-1]*2+1;
        l[i]=l[i-1]*2+3;
    }

    ll lb=1, ub=l[n];
    ll ans=0;
    while(n--){ // [lb, ub]
        ll mid=(lb+ub)/2;

        if(x==lb){
            break;
        }
        else if(lb<x && x<mid){
            ub=mid-1;
            lb++;
            if(n==0) ans++;
        }
        else if(x==mid){
            ans+=cntP[n]+1;
            break;
        }
        else if(mid<x && x<ub){
            lb=mid+1;
            ub--;
            ans+=cntP[n]+1;
            if(n==0) ans++;
        }
        else if(x==ub){
            ans+=cntP[n+1];
            break;
        }
    }
    cout << ans << endl;
}
