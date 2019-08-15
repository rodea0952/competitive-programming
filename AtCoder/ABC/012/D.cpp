#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int d[310][310];

void warshall_floyd(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            d[i][j]=1e9;
        }
    }

    for(int i=0; i<m; i++){
        int a, b, t; cin>>a>>b>>t;
        a--, b--;
        d[a][b]=t, d[b][a]=t;
    }

    warshall_floyd(n);

    int ans=1e9;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<n; j++){
            sum=max(sum, d[i][j]);
        }
        ans=min(ans, sum);
    }
    cout << ans << endl;
}