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
    vector<int> c(n);
    for(int i=0; i<n; i++) cin>>c[i];

    double ans=0;
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(i == j) continue;
            if(c[i] % c[j] == 0) cnt++;
        }
        if(cnt == 0) ans += 1.0;
        else if(cnt % 2 == 1) ans += 0.5;
        else ans += ((double)(cnt+2) / (2*cnt+2));
    }
    cout << fixed << setprecision(10) << ans << endl;
}