#include <bits/stdc++.h>
using namespace std;

int dl[210][210];
int ds[210][210];
int dp[1010][210];
// 何回目、船の場所

void init(){
    for(int i=0; i<210; i++){
        for(int j=0; j<210; j++){
            if(i == j) dl[i][j] = ds[i][j] = 0;
            else dl[i][j] = ds[i][j] = 1e7;
        }
    }

    for(int i=0; i<1010; i++){
        for(int j=0; j<210; j++){
            dp[i][j] = 1e7;
        }
    }

    return ;
}

int main(){
    while(1){
        init();
        int n, m; cin>>n>>m;
        if(n == 0) return 0;

        for(int i=0; i<m; i++){
            int x, y, t; cin>>x>>y>>t;
            char s; cin>>s;
            x--, y--;

            if(s == 'L'){
                dl[x][y] = min(dl[x][y], t);
                dl[y][x] = min(dl[y][x], t);
            }
            else{
                ds[x][y] = min(ds[x][y], t);
                ds[y][x] = min(ds[y][x], t);
            }
        }

        int r; cin>>r;
        vector<int> z(r);
        for(int i=0; i<r; i++){
            cin>>z[i];
            z[i]--;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dl[i][j] = min(dl[i][j], dl[i][k] + dl[k][j]);
                    ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
                }
            }
        }

        dp[0][z[0]] = 0;

        for(int i=0; i<r-1; i++){
            for(int j=0; j<n; j++){
                int cur = z[i];
                int nxt = z[i+1];

                // cur -> land -> nxt
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dl[cur][nxt]);
                    
                // cur -> land -> sea -> land -> nxtS
                for(int k=0; k<n; k++){
                    dp[i+1][k] = min(dp[i+1][k], dp[i][j] + dl[cur][j] + ds[j][k] + dl[k][nxt]);
                }
            }
        }

        int ans = 1e7;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[r-1][i]);
        }

        cout << ans << endl;
    }
}