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
    int n, m; cin>>n>>m;
    vector<int> indeg(n+10, 0);
    vector<vector<int>> g(n+10);
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        x--, y--;
        g[x].eb(y);
        indeg[y]++;
    }

    queue<int> que;
    for(int i=0; i<n; i++){
        if(indeg[i]==0){
            que.push(i);
        }
    }

    vector<int> dp(n+10, 0);
    while(que.size()){
        int cv=que.front(); que.pop();

        for(auto nv:g[cv]){
            indeg[nv]--;

            dp[nv]=max(dp[nv], dp[cv]+1);

            if(indeg[nv]==0){
                que.push(nv);
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<n; i++){
        chmax(ans, dp[i]);
    }
    cout << ans << endl;
}