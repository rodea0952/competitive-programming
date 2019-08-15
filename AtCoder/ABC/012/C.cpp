#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n; cin>>n;
    n=2025-n;
    
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(i*j==n){
                cout << i << " x " << j << endl;
            }
        }
    }
}