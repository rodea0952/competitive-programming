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
    int h, w; cin>>h>>w;
    char s[60][60];
    int white_cnt=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>s[i][j];
            if(s[i][j] == '.') white_cnt++;
        }
    }

    queue<T> que;
    que.push(T(0, 0, 1));
    while(!que.empty()){
        int py, px, cnt;
        tie(py, px, cnt)=que.front(); que.pop();

        if(py == h-1 && px == w-1){
            cout << white_cnt - cnt << endl;
            return 0;
        }

        for(int i=0; i<4; i++){
            int ny=py+dy[i], nx=px+dx[i];

            if(ny >= 0 && ny < h && nx >= 0 && nx < w){
                if(s[ny][nx] == '.'){
                    que.push(T(ny, nx, cnt+1));
                    s[ny][nx] = '#';
                }
            }
        }
    }
    cout << -1 << endl;
}