#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ll dp[100010][10];

int main(){
    string s; cin>>s;
    int n=s.size();

    string t="ABC";

    for(int i=n; i>=0; i--){
        for(int j=3; j>=0; j--){
            if(i == n){
                if(j == 3) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
            else{
                if(s[i] == '?') dp[i][j] = 3*dp[i+1][j];
                else dp[i][j] = dp[i+1][j];

                if(j < 3){
                    if(s[i] == '?' || s[i] == t[j]) dp[i][j] += dp[i+1][j+1];
                }
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[0][0] % MOD << endl;
}