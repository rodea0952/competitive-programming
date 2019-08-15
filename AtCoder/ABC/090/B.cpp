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
    int a, b; cin>>a>>b;
    int ans=0;
    for(int i=a; i<=b; i++){
        string s=to_string(i);

        bool can_count=true;
        for(int j=0; j<5; j++){
            if(s[j]!=s[4-j]) can_count=false;
        }

        if(can_count) ans++;
    }
    cout << ans << endl;
}
