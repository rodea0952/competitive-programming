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
    int h, w; cin>>h>>w;
    vector<string> a(h);
    queue<T> que;
    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    for(int i=0; i<h; i++){
        cin>>a[i];
        for(int j=0; j<w; j++){
            if(a[i][j] == '#'){
                que.push(T(i, j, 0));
                dist[i][j] = 0;
            }
        }
    }

    while(que.size()){
        int cy, cx, cnt;
        tie(cy, cx, cnt) = que.front();
        que.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(0 <= ny && ny < h && 0 <= nx && nx < w){
                if(a[ny][nx] == '.' && dist[cy][cx] + 1 < dist[ny][nx]){
                    dist[ny][nx] = dist[cy][cx] + 1;
                    que.push(T(ny, nx, cnt+1));
                }
            }
        }
    }

    int ans=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            chmax(ans, dist[i][j]);
        }
    }

    cout << ans << endl;
}
