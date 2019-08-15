#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    int ans=MOD;
    for(int i=1; i<n; i++){
        int a=i, b=n-i;
        int suma=0, sumb=0;
        while(a>0){
            suma+=(a%10);
            a/=10;
        }
        while(b>0){
            sumb+=(b%10);
            b/=10;
        }
        ans=min(ans, suma+sumb);
    }
    cout << ans << endl;
}