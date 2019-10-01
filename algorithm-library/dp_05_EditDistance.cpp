int edit_distance(string s, string t){
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = i;
    for(int i=0; i<=m; i++) dp[0][i] = i;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int cost = (s[i] == t[j] ? 0 : 1);
            dp[i+1][j+1] = min({dp[i][j+1] + 1, dp[i+1][j] + 1, dp[i][j] + cost});
        }
    }

    return dp[n][m];
}