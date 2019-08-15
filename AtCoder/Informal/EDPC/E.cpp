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
    int n, W; cin>>n>>W;
    vector<int> w(n), v(n);
    for(int i=0; i<n; i++) cin>>w[i]>>v[i];

    vector<vector<ll>> dp(n+10, vector<ll>(n*1000+10, INF));
    dp[0][0]=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=n*1000; j++){
            if(j-v[i]>=0) dp[i+1][j]=min(dp[i][j], dp[i][j-v[i]]+w[i]);
            else dp[i+1][j]=dp[i][j];
        }
    }

    int ans=0;
    for(int i=0; i<=n*1000; i++){
        if(dp[n][i]<=W) chmax(ans, i);
    }
    cout << ans << endl;
}