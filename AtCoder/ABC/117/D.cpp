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

const int D=50;

int main(){
    ll n, k; cin>>n>>k;
    vector<ll> bitcnt(D+10, 0);
    for(int i=0; i<n; i++){
        ll a; cin>>a;
        for(int j=0; j<=D; j++){
            if((1LL<<j) & a) bitcnt[j]++; 
        }
    }

    ll ans=0;
    for(int d=D; d>=-1; d--){
        // digit = -1 は X = K のとき

        // digit 桁目について、K = 1 でなければならない
        if(d!=-1 && !(k & (1LL<<d))) continue;

        ll sum=0;
        for(int i=D; i>=0; i--){
            ll mask=(1LL<<i);
            
            if(i>d){
                // d より上位の桁なので K に合わせる
                if(k & mask) sum+=mask*(n-bitcnt[i]);
                else sum+=mask*bitcnt[i];
            }
            else if(i==d){
                // X = 0 でなけらばならない
                sum+=mask*bitcnt[i];
            }
            else{
                // d より下位の桁なので、貪欲に決められる
                sum+=mask*max(bitcnt[i], n-bitcnt[i]);
            }
        }

        chmax(ans, sum);
    }

    cout << ans << endl;
}