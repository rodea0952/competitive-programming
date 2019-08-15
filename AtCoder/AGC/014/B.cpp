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
    vector<int> imos(n+10, 0);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        if(a>b) swap(a, b);
        imos[a]++, imos[b]--;
    }

    bool can_make=true;
    for(int i=1; i<n; i++){
        imos[i]+=imos[i-1];
        if(imos[i]%2!=0) can_make=false;
    }

    cout << (can_make?"YES":"NO") << endl;
}