#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int dp[50][410][410];

int main(){
    int n, ma, mb; cin>>n>>ma>>mb;
    vector<int> a(410, 0), b(410, 0), c(410, 0);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i]>>c[i];

    for(int i=0; i<=40; i++){
        for(int ca=0; ca<=400; ca++){
            for(int cb=0; cb<=400; cb++){
                dp[i][ca][cb]=1e9;
            }
        }
    }

    dp[0][0][0]=0;
    for(int i=0; i<n; i++){
        for(int ca=0; ca<=400; ca++){
            for(int cb=0; cb<=400; cb++){
                if(dp[i][ca][cb] == 1e9) continue;
                dp[i+1][ca][cb]=min(dp[i+1][ca][cb], dp[i][ca][cb]);
                dp[i+1][ca+a[i]][cb+b[i]]=min(dp[i+1][ca+a[i]][cb+b[i]], dp[i][ca][cb]+c[i]);
            }
        }
    }

    int ans=1e9;
    for(int ca=1; ca<=400; ca++){
        for(int cb=1; cb<=400; cb++){
            if(ca*mb == cb*ma){
                ans=min(ans, dp[n][ca][cb]);
            }
        }
    }

    if(ans != 1e9) cout << ans << endl;
    else cout << -1 << endl;
}