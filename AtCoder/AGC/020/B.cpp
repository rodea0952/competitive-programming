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
    ll k; cin>>k;
    vector<ll> a(k);
    for(int i=0; i<k; i++) cin>>a[i];

    ll lb=0, ub=1e18, mid;
    ll minans=1e18+1, maxans=-1;
    while(ub-lb>1){
        mid=(lb+ub)/2;
        ll num=mid;

        for(int i=0; i<k; i++){
            num-=(num%a[i]);
        }

        if(num==2){
            ub=mid;
            chmin(minans, mid);
        }
        else if(2<num) ub=mid;
        else lb=mid;
    }

    lb=0, ub=1e18;
    while(ub-lb>1){
        mid=(lb+ub)/2;
        ll num=mid;

        for(int i=0; i<k; i++){
            num-=(num%a[i]);
        }

        if(num==2){
            lb=mid;
            chmax(maxans, mid);
        }
        else if(num<2) lb=mid;
        else ub=mid;
    }

    if(minans>maxans) cout << -1 << endl;
    else cout << minans << " " << maxans << endl;
}
