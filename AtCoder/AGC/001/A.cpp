#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    vector<int> l(2*n);
    for(int i=0; i<2*n; i++) cin>>l[i];
    sort(l.begin(), l.end());
    int ans=0;
    for(int i=0; i<2*n; i+=2) ans+=l[i];
    cout << ans << endl;
}