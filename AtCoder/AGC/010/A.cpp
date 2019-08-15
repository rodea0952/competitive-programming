#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, cnt=0; cin>>n;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        if(a%2==1) cnt++;
    }
    cout << (cnt%2==0?"YES":"NO") << endl;
}