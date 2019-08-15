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
    int h, w; cin>>h>>w;
    vector<string> a(h);
    for(int i=0; i<h; i++) cin>>a[i];

    vector<vector<ll>> dp(h+10, vector<ll>(w+10, 0));
    dp[0][0]=1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(a[i][j]=='#') continue;

            if(0<=i-1 && 0<=j-1){
                dp[i][j]=max(dp[i][j], dp[i-1][j]+dp[i][j-1]);
            }
            else if(0<=j-1){
                dp[i][j]=max(dp[i][j], dp[i][j-1]);
            }
            else if(0<=i-1){
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
            }
            dp[i][j]%=MOD;
        }
    }
    cout << dp[h-1][w-1] << endl;
}