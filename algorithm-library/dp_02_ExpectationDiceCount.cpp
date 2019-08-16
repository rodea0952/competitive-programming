#include <bits/stdc++.h>
using namespace std;

const int MAX_K=100010;
double dp[MAX_K];
// dp[i] := 和が状態 S から i 以上になるために必要な回数の期待値

int main(){
    int k; cin>>k;
    for(int i=k-1; i>=0; i--){
        for(int j=1; j<=6; j++){
            dp[i]+=(dp[i+j]+1.0)/6.0;
        }
    }

    cout << fixed << setprecision(12) << dp[0] << endl;
}