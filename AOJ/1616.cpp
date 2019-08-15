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
    int n, m;
    while(cin>>n>>m, n){
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];

        int ans=-1;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum=a[i]+a[j];
                if(sum<=m){
                    chmax(ans, sum);
                }
            }
        }

        if(ans==-1) cout << "NONE" << endl;
        else cout << ans << endl;
    }
}