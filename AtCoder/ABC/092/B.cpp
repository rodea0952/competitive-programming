#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, d, x; cin>>n>>d>>x;
    for(int i=0; i<n; i++){
        int a; cin>>a;
        for(int j=1; j<=d; j+=a) x++;
    }
    cout << x << endl;
}