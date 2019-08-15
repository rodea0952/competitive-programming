#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    int d[n+10][n+10];
    memset(d, 0, sizeof(d));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>d[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[i][j]+=d[i][j-1];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            d[j][i]+=d[j-1][i];
        }
    }

    int ans[2510];
    memset(ans, 0, sizeof(ans));
    for(int i=1; i<=n*n; i++){
        int dmax=0;
        for(int j=1; j<=sqrt(i); j++){
            if(i%j==0){
                int h=i/j, w=j;
                for(int y=h; y<=n; y++){
                    for(int x=w; x<=n; x++){
                        dmax=max(dmax, d[y][x]-d[y-h][x]-d[y][x-w]+d[y-h][x-w]);
                    }
                }
                h=j, w=i/j;
                for(int y=h; y<=n; y++){
                    for(int x=w; x<=n; x++){
                        dmax=max(dmax, d[y][x]-d[y-h][x]-d[y][x-w]+d[y-h][x-w]);
                    }
                }
            }
        }
        ans[i]=dmax;
    }

    for(int i=1; i<=n*n; i++){
        if(ans[i-1]>ans[i]){
            ans[i]=ans[i-1];
        }
    }

    int q; cin>>q;
    while(q--){
        int p; cin>>p;
        cout << ans[p] << endl;
    }
}