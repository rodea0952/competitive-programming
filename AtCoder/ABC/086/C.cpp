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
    vector<int> t(n+10, 0), x(n+10, 0), y(n+10, 0);
    for(int i=1; i<=n; i++) cin>>t[i]>>x[i]>>y[i];

    bool flag=true;
    for(int i=0; i<n; i++){
        int dt=t[i+1]-t[i], dx=abs(x[i+1]-x[i]), dy=abs(y[i+1]-y[i]);

        int remainder=0;
        if(dt % 2 == 1) remainder=1;

        if(!(dx + dy <= dt && (dx + dy) % 2 == remainder)){
            flag=false;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}