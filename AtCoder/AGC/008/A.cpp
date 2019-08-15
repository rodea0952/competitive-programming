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
    int x, y; cin>>x>>y;
    if(x>=0 && y>=0){
        if(x<=y) cout << y-x << endl;
        else{
            if(y==0) cout << x+1 << endl;
            else cout << -y+x+2 << endl;
        }
    }
    else if(x>=0 && y<0){
        if(abs(x)==abs(y)) cout << 1 << endl;
        else if(abs(x)>abs(y)) cout << x+y+1 << endl;
        else cout << -x-y+1 << endl;
    }
    else if(x<0 && y>=0){
        if(abs(x)==abs(y)) cout << 1 << endl;
        else if(abs(x)>abs(y)){
            if(y==0) cout << -x << endl;
            else cout << -y-x+1 << endl;
        }
        else cout << y+x+1 << endl;
    }
    else{
        if(x<=y) cout << y-x << endl;
        else cout << x-y+2 << endl;
    }
}