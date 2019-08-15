#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

ll C[1010][1010]; //C[n][k] -> nCk
void comb(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j == 0 || j == i){
                C[i][j]=1LL;
            }
            else{
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
            }
        }
    }
}

int main(){
    comb(1000);
    ll r, c, x, y, d, l; cin>>r>>c>>x>>y>>d>>l;
    ll ans1=(r-x+1)*(c-y+1), ans2=0;
    for(int bit=0; bit<(1<<4); bit++){
        ll h=x, w=y;
        if(bit & 1) h--;
        if(bit & 2) h--;
        if(bit & 4) w--;
        if(bit & 8) w--;
        if(h<0 || w<0) continue;
        
        if(__builtin_popcount(bit)%2) ans2-=C[h*w][d+l];
        else ans2+=C[h*w][d+l];
        ans2+=MOD;
        ans2%=MOD;
    }
    ans2*=C[d+l][d];
    ans2%=MOD;
    cout << ans1*ans2%MOD << endl;
}