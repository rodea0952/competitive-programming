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
    int maxdist=0, id;
    for(int i=2; i<=n; i++){
        cout << "? " << 1 << " " << i << endl;
        int dist; cin>>dist;
        if(maxdist<dist){
            maxdist=dist;
            id=i;
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        if(i==id) continue;
        cout << "? " << id << " " << i << endl;
        int dist; cin>>dist;
        chmax(ans, dist);
    }
    cout << "! " << ans << endl;
}