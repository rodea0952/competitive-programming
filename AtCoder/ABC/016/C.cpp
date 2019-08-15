#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> f(20);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        f[a].push_back(b);
        f[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        vector<bool> not_f(20, false);
        not_f[i] = true;
        for(int j=0; j<f[i].size(); j++){
            not_f[f[i][j]] = true;
        }

        int ans=0;
        for(int j=0; j<f[i].size(); j++){
            for(int k=0; k<f[f[i][j]].size(); k++){
                if(not_f[f[f[i][j]][k]] == false) {
                    not_f[f[f[i][j]][k]] = true;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}