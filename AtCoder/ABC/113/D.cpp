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
    int h, w, k; cin>>h>>w>>k;
    if(w==1){
        cout << 1 << endl;
        return 0;
    }
    ll dp[110][10];
    memset(dp, 0, sizeof(dp));
    dp[0][1]=1;
    for(int i=2; i<=w; i++) dp[0][i]=0;

    for(int i=1; i<=h; i++){
        for(int bit=0; bit<(1<<w-1); bit++){
            bool can_make=true;
            for(int k=0; k<w-1; k++){
                if((1<<k)&bit && (1<<k+1)&bit) can_make=false;
            }

            if(can_make){
                for(int k=w-2; k>=0; k--){
                    if((1<<k)&bit){
                        if(k==w-2){
                            dp[i][1]+=(dp[i-1][2])%MOD;
                            dp[i][2]+=(dp[i-1][1])%MOD;
                        }
                        else if(k==0){
                            dp[i][w]+=(dp[i-1][w-1])%MOD;
                            dp[i][w-1]+=(dp[i-1][w])%MOD;
                        }
                        else{
                            dp[i][w-k]+=(dp[i-1][w-k-1])%MOD;
                            dp[i][w-k-1]+=(dp[i-1][w-k])%MOD;
                        }
                    }
                    else{
                        if(w==3 && k-1>=0 && ((!((1<<k)&bit)) && (!((1<<k-1)&bit)))){
                            dp[i][1]+=(dp[i-1][1])%MOD;
                            dp[i][2]+=(dp[i-1][2])%MOD;
                            dp[i][3]+=(dp[i-1][3])%MOD;
                            k--;
                            /*
                            cout << bit << " " << k << endl;
                            cout << i << "   " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
                            */
                        }
                        else if(k==w-2){
                            if((!((1<<k)&bit)) && (!((1<<k-1)&bit))){
                                dp[i][1]+=(dp[i-1][1])%MOD;
                                dp[i][2]+=(dp[i-1][2])%MOD;
                            }
                            else dp[i][1]+=(dp[i-1][1])%MOD;
                        }
                        else if(k==0){
                            dp[i][w]+=(dp[i-1][w])%MOD;
                        }
                        else{
                            if((!((1<<k)&bit)) && (!((1<<k-1)&bit))){
                                dp[i][w-k]+=(dp[i-1][w-k])%MOD;
                            }
                        }
                    }
                    for(int j=1; j<=w; j++) dp[i][j]%=MOD;
                }
            }
        }
    }

    /*
    for(int i=0; i<=h; i++){
        for(int j=1; j<=w; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[h][k]%MOD << endl;
}