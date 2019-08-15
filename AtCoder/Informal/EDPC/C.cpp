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
    int n; cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i]>>c[i];

    int dp[n][3];
    dp[0][0]=a[0], dp[0][1]=b[0], dp[0][2]=c[0];
    for(int i=1; i<n; i++){
        dp[i][0]=a[i]+max(dp[i-1][1], dp[i-1][2]);
        dp[i][1]=b[i]+max(dp[i-1][0], dp[i-1][2]);
        dp[i][2]=c[i]+max(dp[i-1][0], dp[i-1][1]);
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
}