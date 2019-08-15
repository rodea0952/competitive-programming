#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, int, int> T;

int MOD = 1e9 + 7;
ll INF = 1e18;

int h, w, t;
string s[20];
int sx, sy, gx, gy;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool dijkstra(int now_cost){
    vector<vector<ll>> dist(20, vector<ll>(20, INF));
    priority_queue<T, vector<T>, greater<T>> que;
    dist[sy][sx]=0;
    que.push(T(0, sy, sx));

    while(!que.empty()){
        ll cost;
        int y, x;
        tie(cost, y, x) = que.top(); que.pop();
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i], nx = x + dx[i];

            if(0 <= ny && ny < h && 0 <= nx && nx < w){
                if(s[ny][nx] == '#'){
                    if(dist[ny][nx] > cost + now_cost){
                        dist[ny][nx] = cost + now_cost;
                        que.push(T(cost+now_cost, ny, nx));
                    }
                }
                else{
                    if(dist[ny][nx] > cost + 1){
                        dist[ny][nx] = cost + 1;
                        que.push(T(cost+1, ny, nx));
                    }
                }
            }
        }
    }    
    if(dist[gy][gx] <= t) return true;
    else return false;
}


int main() {
    cin>>h>>w>>t;
    for(int i=0; i<h; i++){
        cin>>s[i];
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] == 'S'){
                sy=i, sx=j;
            }
            else if(s[i][j] == 'G'){
                gy=i, gx=j;
            }
        }
    }

    int left=1, right=1e9, mid;
    while(right - left > 1){
        mid=(right+left)/2;

        if(dijkstra(mid)) left=mid;
        else right=mid;
    }
    cout << left << endl;
}