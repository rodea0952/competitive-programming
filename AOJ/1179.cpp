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
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int y, m, d; cin>>y>>m>>d;

        int ans=0;
        while(1){
            if(y==1000 && m==1 && d==1) break;

            ans++;
            d++;
            if(y%3==0){
                if(d==21){
                    m++;
                    d=1;
                }
            }
            else{
                if(m%2==1){
                    if(d==21){
                        m++;
                        d=1;
                    }
                }
                else{
                    if(d==20){
                        m++;
                        d=1;
                    }
                }
            }

            if(m==11){
                y++;
                m=1;
            }
        }

        cout << ans << endl;
    }
}