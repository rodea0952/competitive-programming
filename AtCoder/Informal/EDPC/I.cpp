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

double dp[3010][3010];

int main(){
    int n; cin>>n;
    vector<double> p(n);
    for(int i=0; i<n; i++) cin>>p[i];

    dp[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            dp[i+1][j]+=dp[i][j]*(1-p[i]);
            dp[i+1][j+1]+=dp[i][j]*p[i];
        }
    }
    
    double ans=0;
    for(int i=0; i<=n; i++){
        if(i>n/2) ans+=dp[n][i];
    }
    cout << fixed << setprecision(12) << ans << endl;
}