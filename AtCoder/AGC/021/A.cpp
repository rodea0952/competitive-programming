#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    ll n; cin>>n;
    if(1<=n && n<=9){
        cout << n << endl;
        return 0;
    }
    
    int digit=0;
    bool f=true;
    while(n>0){
        digit++;
        if(n%10 != 9) f=false;
        n/=10;

        if(1<=n && n<=9 && f){
            cout << n+9*digit << endl;
            return 0;
        }

        if(n==1) cout << 9*digit << endl;
        else if(2<=n && n<=9) cout << (n-1)+9*digit << endl;
    }
}
