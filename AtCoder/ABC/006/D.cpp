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
    int n; cin>>n;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin>>c[i];

    vector<ll> dp(n, INF);
    for(int i=0; i<n; i++){
        *lower_bound(dp.begin(), dp.end(), c[i])=c[i];
    }

    cout << n - (lower_bound(dp.begin(), dp.end(), INF) - dp.begin()) << endl;
}