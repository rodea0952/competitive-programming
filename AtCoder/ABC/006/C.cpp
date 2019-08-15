#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n, m; cin>>n>>m;

    for(int z=0; m-2*n-2*z>=0; z++){
        int y=m-2*n-2*z;
        int x=n-y-z;
        if(x >= 0){
            cout << x << " " << y << " " << z << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}