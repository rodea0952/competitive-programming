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
    vector<int> c(n+10, 0), s(n+10, 0), f(n+10, 0);
    for(int i=0; i<n-1; i++) cin>>c[i]>>s[i]>>f[i];

    for(int i=0; i<n; i++){
        int ans=c[i]+s[i];
        for(int j=i+1; j<n-1; j++){
            if(ans > s[j]){
                ans = ((ans + (f[j] - 1)) / f[j]) * f[j];
            }
            else{
                ans = s[j];
            }
            ans += c[j];
        }
        cout << ans << endl;
    }
}