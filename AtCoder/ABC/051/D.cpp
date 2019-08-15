#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int d[110][110];

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
            if(i == j) d[i][j]=0;
            else d[i][j]=MOD;
        }
    }

    vector<int> a(m+10), b(m+10), c(m+10);
    for(int i=0; i<m; i++){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--, b[i]--;
        d[a[i]][b[i]]=c[i];
        d[b[i]][a[i]]=c[i];
    }

    warshall_floyd(n);

    int ans=0;
    for(int i=0; i<m; i++){
        if(d[a[i]][b[i]] < c[i]) ans++;
    }
    cout << ans << endl;
}
