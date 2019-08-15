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

int dp[10010][60][60];

int main(){
    int W; cin>>W;
    int n, K; cin>>n>>K;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];

    for(int k=0; k<n; k++){
        for(int j=1; j<=K; j++){
            for(int i=0; i<=W; i++){
                if(i-a[k]>=0) dp[i][j][k+1]=max(dp[i-a[k]][j-1][k]+b[k], dp[i][j][k]);
                else dp[i][j][k+1]=dp[i][j][k];
            }
        }
    }
    cout << dp[W][K][n] << endl;
}