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
    int a, b; cin>>a>>b;
    a--, b--;
    char g[100][100];
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            g[i][j]=(i<50?'#':'.');
        }
    }

    for(int i=0; i<45; i++){
        if(i%2==1 || a==0) continue;
        for(int j=0; j<100; j++){
            if(i%4==0 && j%2==0){
                g[i][j]='.';
                a--;
            }
            else if(i%4==2 && j%2==1){
                g[i][j]='.';
                a--;
            }

            if(a==0) goto END1;
        }
    }
    END1:;

    for(int i=99; i>=55; i--){
        if(i%2==0 || b==0) continue;
        for(int j=0; j<100; j++){
            if(i%4==3 && j%2==0){
                g[i][j]='#';
                b--;
            }
            else if(i%4==1 && j%2==1){
                g[i][j]='#';
                b--;
            }

            if(b==0) goto END2;
        }
    }
    END2:;

    cout << 100 << " " << 100 << endl;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            cout << g[i][j];
        }
        cout << endl;
    }
}