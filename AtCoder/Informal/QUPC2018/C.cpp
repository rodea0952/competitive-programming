#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    int h, w, x; cin>>h>>w>>x;
    vector<string> s(h);

    int sy, sx, gy, gx;
    queue<P> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    for(int i=0; i<h; i++){
        cin>>s[i];

        for(int j=0; j<w; j++){
            if(s[i][j] == 'S'){
                sy = i;
                sx = j;
            }

            if(s[i][j] == 'G'){
                gy = i;
                gx = j;
            }

            if(s[i][j] == '@'){
                s[i][j] = '#';
                que.push(P(i, j));
                dist[i][j] = 0;
            }
        }
    }

    while(que.size()){
        int cy = que.front().fs;
        int cx = que.front().sc;
        que.pop();

        if(dist[cy][cx] == x) continue;

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(0 <= ny && ny < h && 0 <= nx && nx < w){
                if(s[ny][nx] != '#' && dist[ny][nx] == -1){
                    dist[ny][nx] = dist[cy][cx] + 1;
                    s[ny][nx] = '#';
                    que.push(P(ny, nx));
                }
            }
        }
    }

    queue<T> q;
    q.push(T(sy, sx, 0));
    s[sy][sx] = '#';
    while(q.size()){
        int cy, cx, cost;
        tie(cy, cx, cost) = q.front();
        q.pop();

        if(cy == gy && cx == gx){
            cout << cost << endl;
            return 0;
        }

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(0 <= ny && ny < h && 0 <= nx && nx < w){
                if(s[ny][nx] != '#'){
                    s[ny][nx] = '#';
                    q.push(T(ny, nx, cost + 1));
                }
            }
        }
    }

    cout << -1 << endl;
}