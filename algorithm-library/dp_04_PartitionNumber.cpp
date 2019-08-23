// dp[i][j] := 数 j を i 分割する総数
vector<vector<ll>> dp(1010, vector<ll>(1010, 0));

void partition_function(){
    dp[0][0] = 1;
    for(int i=1; i<=1005; i++){
        for(int j=0; j<=1005; j++){
            if(0 <= j - i){
                (dp[i][j] = dp[i-1][j] + dp[i][j-i]) %= MOD;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return ;
}