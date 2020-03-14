int LCS(string s, string t){
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int cost = s[i] == t[j];
            dp[i+1][j+1] = max({dp[i][j+1], dp[i+1][j], dp[i][j] + cost});
        }
    }

    return dp[n][m];
}