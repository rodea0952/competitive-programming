#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int a, b, c; cin>>a>>b>>c;
    if(a == b && b == c){
        if(a%2 == 0) cout << -1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    ll num=2, ans=0;
    while(1){
        if(!(((a+b)%num == 0 && (b+c)%num == 0 && (c+a)%num == 0) && (a%(num/2) == 0 && b%(num/2) == 0 && c%(num/2) == 0))) break;
        ans++;
        num*=2;
    }
    cout << ans << endl;
}