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
    vector<int> p_imos(100010, 0);
    for(int i=0; i<n; i++) {
        int l, r, s; cin>>l>>r>>s;
        l--, r--;

        if(l == 0){
            p_imos[r+1] += s;
            p_imos[m] -= s;
        }
        else if(r == m-1){
            p_imos[0] += s;
            p_imos[l] -= s;
        }
        else{
            p_imos[0] += s;
            p_imos[l] -= s;
            p_imos[r+1] += s;
            p_imos[m] -= s;
        }
    }

    int ans=0;
    vector<int> imos(100010, 0);
    for(int i=0; i<=m; i++){
        if(i == 0) imos[i] = p_imos[i];
        else imos[i] = imos[i-1] + p_imos[i];
        ans = max(ans, imos[i]);
    }
    cout << ans << endl;
}