#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    string s, t; cin>>s>>t;
    int n=s.size(), m=t.size();

    vector<vector<string>> dp(2, vector<string>(m+1, ""));
    int cur=0, nxt=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i]==t[j]){
                dp[nxt][j+1]=dp[cur][j]+s[i];
            }
                
            if(dp[nxt][j+1].size()<dp[cur][j+1].size()){
                dp[nxt][j+1]=dp[cur][j+1];
            }
            if(dp[nxt][j+1].size()<dp[nxt][j].size()){
                dp[nxt][j+1]=dp[nxt][j];
            }
        }
        swap(cur, nxt);
    }
    cout << dp[cur][m] << endl; 
}