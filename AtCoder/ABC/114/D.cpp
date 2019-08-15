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
    vector<int> cnt(110, 0);
    for(int i=2; i<=n; i++){
        int num=i;
        for(int j=2; j<=i; j++){
            while(num%j==0){
                num/=j;
                cnt[j]++;
            }
            if(num==1) break;
        }
    }

    ll ans=0;
    for(int i=2; i<=n; i++){ // (74+1)
        if(74<=cnt[i]) ans++;
    }

    ll A=0, B=0;
    for(int i=2; i<=n; i++){ // (2+1)*(24+1)
        if(24<=cnt[i]) B++;
        if(2<=cnt[i]) A++;
    }
    ans+=B*(A-1);

    A=0, B=0;
    for(int i=2; i<=n; i++){ // (4+1)*(14+1)
        if(14<=cnt[i]) B++;
        if(4<=cnt[i]) A++;
    }
    ans+=B*(A-1);

    A=0, B=0;
    for(int i=2; i<=n; i++){ // (2+1)*(4+1)*(4+1)
        if(4<=cnt[i]) B++;
        if(2<=cnt[i]) A++;
    }
    ans+=B*(B-1)*(A-2)/2;

    cout << ans << endl;
}