#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> p_imos(1000010, 0), imos(1000010, 0);
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        p_imos[a]++, p_imos[b+1]--;
    }

    int ans=0;
    for(int i=0; i<=1000000; i++){
        if(i == 0) imos[i] = p_imos[i];
        else imos[i] = imos[i-1] + p_imos[i];
        ans = max(ans, imos[i]);
    }
    cout << ans << endl;
}