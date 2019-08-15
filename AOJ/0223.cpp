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
typedef tuple<int, int, int, int> T;
typedef tuple<int, int, int, int, int> T2;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    while(1){
        int w, h; cin>>w>>h;
        if(w == 0) return 0;

        int tx, ty, kx, ky; cin>>tx>>ty>>kx>>ky;

        vector<vector<int>> d(h+2, vector<int>(w+2, 1));
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                cin>>d[i][j];
            }
        }

        map<T, bool> visited;
        visited[T(ty, tx, ky, kx)] = true;

        bool valid = false;
        queue<T2> que;
        que.push(T2(ty, tx, ky, kx, 0));
        while(que.size()){
            int cy1, cx1, cy2, cx2, cnt;
            tie(cy1, cx1, cy2, cx2, cnt) = que.front();
            que.pop();

            if(100 <= cnt) continue;

            if(cy1 == cy2 && cx1 == cx2){
                cout << cnt << endl;
                valid = true;
                break;
            }

            for(int i=0; i<4; i++){
                int ny1 = cy1 + dy[i];
                int nx1 = cx1 + dx[i];
                int ny2 = cy2 - dy[i];
                int nx2 = cx2 - dx[i];

                if(d[ny1][nx1] == 0 && d[ny2][nx2] == 0 && !visited[T(ny1, nx1, ny2, nx2)]){
                    visited[T(ny1, nx1, ny2, nx2)] = true;
                    que.push(T2(ny1, nx1, ny2, nx2, cnt + 1));
                }
                else if(d[ny1][nx1] == 0 && d[ny2][nx2] == 1 && !visited[T(ny1, nx1, cy2, cx2)]){
                    visited[T(ny1, nx1, cy2, cx2)] = true;
                    que.push(T2(ny1, nx1, cy2, cx2, cnt + 1));
                }
                else if(d[ny1][nx1] == 1 && d[ny2][nx2] == 0 && !visited[T(cy1, cx1, ny2, nx2)]){
                    visited[T(cy1, cx1, ny2, nx2)] = true;
                    que.push(T2(cy1, cx1, ny2, nx2, cnt + 1));
                }
            }
        }

        if(!valid){
            cout << "NA" << endl;
        }
    }
}