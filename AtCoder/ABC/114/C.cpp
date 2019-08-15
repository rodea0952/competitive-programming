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

vector<ll> v;

void calc(ll n){
    if(n>1e9) return;

    v.eb(n);
    calc(n*10+3);
    calc(n*10+5);
    calc(n*10+7);

    return;    
}

int main(){
    int n; cin>>n;
    calc(0);
    vector<ll> ans;
    for(int i=0; i<v.size(); i++){
        ll num=v[i];
        bool exist3=false, exist5=false, exist7=false;
        while(num>0){
            if(num%10==3) exist3=true;
            if(num%10==5) exist5=true;
            if(num%10==7) exist7=true;
            num/=10;            
        }

        if(exist3 && exist5 && exist7) ans.eb(v[i]);
    }

    int cnt=0;
    for(int i=0; i<ans.size(); i++){
        if(ans[i]<=n) cnt++;
    }
    cout << cnt << endl;
}