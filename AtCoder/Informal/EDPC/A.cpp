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
    vector<int> h(n+10);
    for(int i=0; i<n; i++) cin>>h[i];

    vector<int> dp(n+10);
    dp[1]=abs(h[0]-h[1]);
    dp[2]=abs(h[0]-h[2]);
    for(int i=3; i<n; i++){
        dp[i]=min(dp[i-2]+abs(h[i-2]-h[i]), dp[i-1]+abs(h[i-1]-h[i]));
    }
    cout << dp[n-1] << endl;
}