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
    int n, w; cin>>n>>w;
    vector<int> wei(n), val(n);
    for(int i=0; i<n; i++) cin>>wei[i]>>val[i];

    vector<vector<ll>> dp(n+10, vector<ll>(w+10, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<=w; j++){
            if(j-wei[i]>=0) dp[i+1][j]=max(dp[i][j], dp[i][j-wei[i]]+val[i]);
            else dp[i+1][j]=dp[i][j];
        }
    }
    cout << dp[n][w] << endl;
}