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
    int a, b, c, x; cin>>a>>b>>c>>x;
    int ans=0;
    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            for(int k=0; k<=c; k++){
                if(500*i+100*j+50*k==x) ans++;
            }
        }
    }
    cout << ans << endl;
}