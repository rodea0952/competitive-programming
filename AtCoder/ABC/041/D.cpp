#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, m; cin>>n>>m;
    int g[20][20];

    memset(g, 0, sizeof(g));
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        x--, y--;
        g[x][y]=-1;
    }

    ll dp[1<<16];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;

    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(i & (1<<j)){

                // S-{v} (i-{j})
                int cur=i&~(1<<j);
                bool f=true;

                for(int k=0; k<n; k++){
                    if((cur & (1<<k)) && g[j][k] == -1) f=false;
                }

                if(f) dp[i] += dp[cur];
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
}