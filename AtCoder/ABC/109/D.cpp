#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int h, w; cin>>h>>w;
    int a[510][510];
    bool visited[510][510];
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>a[i][j];
            visited[i][j]=false;
        }
    }

    for(int i=0; i<=w; i++) a[0][i]=MOD;
    for(int i=0; i<=h; i++) a[i][0]=MOD;
    for(int i=0; i<=w; i++) a[h+1][i]=MOD;
    for(int i=0; i<=h; i++) a[i][w+1]=MOD;

    int ans=0;
    vector<int> ans1(260000), ans2(260000), ans3(260000), ans4(260000);
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            visited[i][j]=true;
            if(a[i][j] % 2 == 0) continue;

            bool flag=true;
            for(int k=0; k<4; k++){
                int ny=dy[k], nx=dx[k];

                if(a[i+ny][j+nx] != MOD && visited[i+ny][j+nx] == false){
                    if(a[i+ny][j+nx] % 2 == 1){
                        flag=false;
                        a[i][j]--;
                        a[i+ny][j+nx]++;
                        ans++;
                        ans1[ans]=i, ans2[ans]=j, ans3[ans]=i+ny, ans4[ans]=j+nx;
                        break;
                    }
                }
            }

            if(flag){
                if(j != w){
                    a[i][j]--;
                    a[i][j+1]++;
                    ans++;
                    ans1[ans]=i, ans2[ans]=j, ans3[ans]=i, ans4[ans]=j+1;
                }
                else if(i != h){
                    a[i][j]--;
                    a[i+1][j]++;
                    ans++;
                    ans1[ans]=i, ans2[ans]=j, ans3[ans]=i+1, ans4[ans]=j;
                }
            }
        }
    }

    cout << ans << endl;
    for(int i=1; i<=ans; i++){
        cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << " " << ans4[i] << endl;
    }
}