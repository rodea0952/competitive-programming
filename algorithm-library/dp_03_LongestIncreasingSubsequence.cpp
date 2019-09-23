int LIS(vector<int> &a){
    // dp[i] := 長さが i+1 であるような増加部分列における最終要素の最小値
    int n = a.size();
    vector<int> dp(n, inf);
    for(int i=0; i<n; i++){
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }

    return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}