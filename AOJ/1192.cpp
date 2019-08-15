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
    while(1){
        int x, y, s; cin>>x>>y>>s;
        if(x==0) return 0;

        int ans=0;
        for(int i=1; i<s; i++){
            for(int j=1; j<s; j++){

                if(i*(100+x)/100 + j*(100+x)/100 == s){
                    chmax(ans, i*(100+y)/100 + j*(100+y)/100);
                }
            }
        }

        cout << ans << endl;
    }
}