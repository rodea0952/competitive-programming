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
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, m; cin>>n>>m;
    vector<int> a(n);
    vector<int> head(n), tail(n);
    ll ans=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        ans+=abs(a[i]-i);
        head[i]=(min(i, a[i]));
        tail[i]=(max(i, a[i]));
    }

    sort(head.begin(), head.end(), greater<int>());
    sort(tail.begin(), tail.end());

    int cnt=0;
    for(int i=0; i<m; i++){
        if(head[cnt]-tail[cnt]>0){
            ans+=(head[cnt]-tail[cnt])*2;
            cnt++;
        }
        else break;
    }
    cout << ans << endl;
}