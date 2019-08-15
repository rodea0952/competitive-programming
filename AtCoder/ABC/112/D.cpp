#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int n, m; cin>>n>>m;
    bool is_prime=true;
    for(int i=2; i<=sqrt(m); i++){
        if(m%i == 0) is_prime=false;
    }

    if(is_prime) cout << 1 << endl;
    else{
        for(int i=n; i<=m; i++){
            if(m%i == 0){
                cout << m/i << endl;
                return 0;
            }
        }
    }
}