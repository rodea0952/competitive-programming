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

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n; cin>>n;
    int a[3];
    int cnt=0;
    while(n>0){
        a[cnt++]=(n%10);
        n/=10;
    }
    for(int i=2; i>=0; i--){
        if(a[i]==1) cout << 9;
        else cout << 1;
    }
    cout << endl;
}