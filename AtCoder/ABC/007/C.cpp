#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int r, c, sy, sx, gy, gx; cin>>r>>c>>sy>>sx>>gy>>gx;
    sy--, sx--, gy--, gx--;
    vector<string> s(60);
    for(int i=0; i<r; i++) cin>>s[i];
    
    queue<T> que;
    que.push(T(sy, sx, 0));

    while(!que.empty()){
        int py, px, cnt;
        tie(py, px, cnt) = que.front(); que.pop();

        if(py == gy && px == gx){
            cout << cnt << endl;
            return 0;
        }

        for(int i=0; i<4; i++){
            int ny = py + dy[i], nx = px + dx[i];

            if(ny >= 0 && ny < r && nx >= 0 && nx < c){
                if(s[ny][nx] == '.'){
                    que.push(T(ny, nx, cnt+1));
                    s[ny][nx] = '#';
                }
            }
        }
    }
}