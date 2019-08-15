#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

vector<vector<int>> d(310, vector<int>(310, MOD));

void warshall_floyd(int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
    int n, m; cin>>n>>m;
    vector<int> house_next;
    vector<int> house_next_d(310, MOD);
    for(int i=0; i<m; i++) {
        int u, v, l; cin>>u>>v>>l;
        u--, v--;
        if(u == 0) {
            house_next_d[v]=l;
            house_next.push_back(v);
            continue;
        }
        d[u][v]=l;
        d[v][u]=l;
    }

    for(int i=0; i<n; i++) d[i][i]=0;

    warshall_floyd(n);

    int MIN=MOD;
    for(auto i : house_next){
        for(auto j : house_next){
            if(i == j) continue;

            MIN = min(MIN, d[i][j] + house_next_d[i] + house_next_d[j]);
        }
    }

    if(MIN == MOD) cout << -1 << endl;
    else cout << MIN << endl;
}