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
    int n, k; cin>>n>>k;
    vector<int> h(n+10);
    for(int i=0; i<n; i++) cin>>h[i];

    vector<int> dp(n+10, 1e9);
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(0<=i-j) dp[i]=min(dp[i], dp[i-j]+abs(h[i-j]-h[i]));
        }
    }
    cout << dp[n-1] << endl;
}