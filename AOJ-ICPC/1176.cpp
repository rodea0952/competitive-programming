#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int h, w, s;
int allsum;
int u[32][32];
int psum[33][33];
int sum[32][32][32][32];
P dp[32][32][32][32];

P dfs(int ly, int lx, int hy, int hx){
    if(dp[ly][lx][hy][hx].first != 0){
        return dp[ly][lx][hy][hx];
    }

    P res = P(1, s - (allsum - sum[ly][lx][hy][hx]));

    for(int i=ly; i<hy; i++){
        if(allsum - sum[ly][lx][i][hx] > s) continue;
        if(allsum - sum[i+1][lx][hy][hx] > s) continue;


        P a = dfs(ly, lx, i, hx);
        P b = dfs(i+1, lx, hy, hx);
        P ab = P(a.first + b.first , min(a.second, b.second));
        res = max(res, ab);
    }

    for(int i=lx; i<hx; i++){
        if(allsum - sum[ly][lx][hy][i] > s) continue;
        if(allsum - sum[ly][i+1][hy][hx] > s) continue;

        P a = dfs(ly, lx, hy, i);
        P b = dfs(ly, i+1, hy, hx);
        P ab = P(a.first + b.first , min(a.second, b.second));
        res = max(res, ab);
    }

    return dp[ly][lx][hy][hx] = res;
}

int main(){
    while(1){
        allsum = 0;
        memset(psum, 0, sizeof(psum));
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));

        cin>>h>>w>>s;
        if(h == 0) return 0;

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>u[i][j];
                allsum += u[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                psum[i+1][j+1] = psum[i+1][j] + u[i][j];
            }
        }

        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                psum[j+1][i+1] += psum[j][i+1];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=i; j<h; j++){
                for(int k=0; k<w; k++){
                    for(int l=k; l<w; l++){
                        sum[i][k][j][l] = psum[j+1][l+1] - psum[i][l+1] - psum[j+1][k] + psum[i][k];
                    }
                }
            }
        }

        P ans = dfs(0, 0, h-1, w-1);

        cout << ans.first << " " << ans.second << endl;
    }
}