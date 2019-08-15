#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int c[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>c[i][j];
        }
    }

    bool flag=true;
    for(int i=0; i<2; i++){
        if(!(c[i][0] - c[i+1][0] == c[i][1] - c[i+1][1])) flag=false;
        if(!(c[i][1] - c[i+1][1] == c[i][2] - c[i+1][2])) flag=false;
        if(!(c[i][0] - c[i+1][0] == c[i][2] - c[i+1][2])) flag=false;
    }

    for(int i=0; i<2; i++){
        if(!(c[0][i] - c[0][i+1] == c[1][i] - c[1][i+1])) flag=false;
        if(!(c[1][i] - c[1][i+1] == c[2][i] - c[2][i+1])) flag=false;
        if(!(c[0][i] - c[0][i+1] == c[2][i] - c[2][i+1])) flag=false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}