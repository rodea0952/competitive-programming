#include <bits/stdc++.h>
using namespace std;

const int MAX_N=2010;
double dp[MAX_N][MAX_N*6];
// dp[i][j] := i回サイコロを振ったとき、出た目の和がjになる確率

int main(){
    int n, m; cin>>n>>m;
    dp[0][0]=1.0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=m; j++){
            for(int k=1; k<=6; k++){
                dp[i+1][min(m, j+k)]+=dp[i][j]/6.0;
            }
        }
    }

    cout << fixed << setprecision(12) << dp[n][m] << endl;
}