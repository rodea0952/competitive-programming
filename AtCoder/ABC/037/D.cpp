#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int h, w;
ll a[1010][1010], dp[1010][1010];

int dfs(int y, int x){
    ll ans=1;
    if(dp[y][x] != 0) return dp[y][x];

    for(int i=0; i<4; i++){
        int ny=y+dy[i], nx=x+dx[i];

        if(0<=ny && ny<h && 0<=nx && nx<w && a[y][x]<a[ny][nx]){
            ans+=dfs(ny, nx);
            ans%=MOD;
        }
    }

    return dp[y][x]=ans;
}

int main(){
    cin>>h>>w;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
        }
    }

    ll ans=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            ans+=dfs(i, j);
            ans%=MOD;
        }
    }
    cout << ans << endl;
}