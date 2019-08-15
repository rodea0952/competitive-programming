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
    int a[2][100];
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    int ans=0;
    for(int down=0; down<n; down++){
        int candy=0;
        for(int i=0; i<n; i++){
            if(i < down){
                candy += a[0][i];
            }
            else if(i == down){
                candy += a[0][i];
                candy += a[1][i];
            }
            else{
                candy += a[1][i];
            }
        }
        ans = max(ans, candy);
    }
    cout << ans << endl;
}