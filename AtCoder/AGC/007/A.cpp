#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD=1e9+7;
ll INF=1e18;

int dx[]={1, 0};
int dy[]={0, 1};

int main(){
    int h, w; cin>>h>>w;
    char a[10][10];
    int cnt=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
            if(a[i][j]=='#') cnt++;
        }
    }

    if(cnt!=h+w-1){
        cout << "Impossible" << endl;
        return 0;
    }

    queue<P> que;
    que.push(P(0, 0));
    while(que.size()){
        int cy, cx;
        tie(cy, cx)=que.front(); que.pop();

        if(cy==h-1 && cx==w-1){
            cout << "Possible" << endl;
            return 0;
        }

        for(int i=0; i<2; i++){
            int ny=cy+dy[i], nx=cx+dx[i];
            if(ny<h && nx<w){
                if(a[ny][nx]=='#'){
                    a[ny][nx]='.';
                    que.push(P(ny, nx));
                }
            }
        }
    }
    cout << "Impossible" << endl;
}