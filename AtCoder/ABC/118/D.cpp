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

int match[]={2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    int n, m; cin>>n>>m;
    vector<int> a(m);
    vector<bool> canuse(m, false);
    for(int i=0; i<m; i++){
        cin>>a[i];
        a[i]--;
        canuse[a[i]]=true;
    }

    vector<int> dp(n+10, -1);
    dp[0]=0;
    for(int i=0; i<10; i++){
        if(!canuse[i]) continue;
        for(int j=0; j+match[i]<=n; j++){
            dp[j+match[i]]=max(dp[j+match[i]], dp[j]+1);
        }
    }

    string ans;
    int rem=n;
    while(rem){
        for(int i=8; i>=0; i--){
            if(!canuse[i]) continue;
            if(rem<match[i]) continue;

            if(dp[rem-match[i]]==dp[rem]-1){
                rem-=match[i];
                ans+=(char)('0'+i+1);
                break;
            }
        }
    }
    cout << ans << endl;
}