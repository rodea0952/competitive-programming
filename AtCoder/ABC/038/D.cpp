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
    vector<int> w(n), h(n);
    for(int i=0; i<n; i++) cin>>w[i]>>h[i];

    vector<int> dp(n+10, 0);
    dp[0]=1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){

        }
    }
}