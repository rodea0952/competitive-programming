#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, a, b; cin>>n>>a>>b;
    if((b-a-1)%2 == 0) cout << "Borys" << endl;
    else cout << "Alice" << endl;
}