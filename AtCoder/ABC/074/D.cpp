#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

ll d[310][310];

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
    int n; cin>>n;
    int a[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
            d[i][j]=a[i][j];
        }
    }

    warshall_floyd(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=d[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    ll ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            bool remove=false;
            for(int k=0; k<n; k++){
                if(i==k || j==k) continue;
                if(d[i][k]+d[k][j]==d[i][j]) remove=true;
            }
            if(!remove) ans+=d[i][j]; 
        }
    }
    cout << ans << endl;
}