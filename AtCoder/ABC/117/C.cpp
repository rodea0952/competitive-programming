#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, m; cin>>n>>m;
    vector<int> x(m);
    for(int i=0; i<m; i++) cin>>x[i];
    sort(x.begin(), x.end());

    vector<int> gap(m-1);
    for(int i=0; i<m-1; i++) gap[i]=x[i+1]-x[i];
    sort(gap.begin(), gap.end(), greater<int>());

    ll ans=0;
    for(int i=0; i<m-1; i++){
        if(n-1<=i) ans+=gap[i];
    }
    cout << ans << endl;
}