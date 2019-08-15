#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, k;
int T[10][10];

bool dfs(int q, int value){
    if(q == n) return (value == 0);

    for(int i=0; i<k; i++){
        if(dfs(q+1, value^T[q][i])) return true;
    }
    return false;
}

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin>>T[i][j];
        }
    }

    if(dfs(0, 0)) cout << "Found" << endl;
    else cout << "Nothing" << endl;

}