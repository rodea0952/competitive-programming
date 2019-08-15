#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

ll gcd(ll x, ll y){
    if(y==0) return x;
    else return gcd(y, x%y);
}

int main(){
    ll a, b; cin>>a>>b;
    vector<ll> odd, even;
    for(ll i=a; i<=b; i++){
        if(i%2!=0){
            odd.push_back(i);
        }
        else{
            even.push_back(i);
        }
    }

    int ans=0;
    for(int i=0; i<(1LL<<odd.size()); i++){
        
        bool valid=true;

        vector<ll> v;
        for(int j=0; j<odd.size(); j++){
            if(i & (1LL<<j)){
                v.push_back(odd[j]);
            }
        }

        for(int j=0; j<v.size(); j++){
            for(int k=j+1; k<v.size(); k++){
                if(gcd(v[j], v[k])!=1){
                    valid=false;
                }
            }
        }            

        if(valid){
            ans++;
        }
        else{
            continue;
        }

        for(int j=0; j<even.size(); j++){
            valid=true;
            for(int k=0; k<v.size(); k++){
                if(gcd(even[j], v[k])!=1){
                    valid=false;
                }
            }

            if(valid){
                ans++;
            }
        }
    }

    cout << ans << endl;
}