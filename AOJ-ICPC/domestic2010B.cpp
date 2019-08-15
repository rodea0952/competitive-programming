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
    while(1){
        int w, h; cin>>w>>h;
        if(w == 0) return 0;

        vector<vector<int>> bo(2*h-1, vector<int>(2*w-1, -1)); 
        for(int i=0; i<2*h-1; i++){
            for(int j=0; j<2*w-1; j++){
                if(i % 2 == 0 && j % 2 == 1) cin>>bo[i][j];
                if(i % 2 == 1 && j % 2 == 0) cin>>bo[i][j];
            }
        }

        queue<T> que;
        que.push(T(0, 0, 0));
        while(que.size()){
            int cy, cx, cost;
            tie(cy, cx, cost) = que.front();
            que.pop();

            if(cy == 2 * h - 2 && cx == 2 * w - 2){
                cout << cost + 1 << endl;
                goto END;
            }

            for(int i=0; i<4; i++){
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(0 <= ny && ny < 2 * h - 1 && 0 <= nx && nx < 2 * w - 1){
                    if(i == 0 && nx + 1 < 2 * w - 1 && bo[ny][nx] == 0 && bo[ny][nx+1] == -1){
                        bo[ny][nx] = 2;
                        bo[ny][nx+1] = 2;
                        que.push(T(ny, nx+1, cost+1));
                    }
                    if(i == 1 && 0 <= ny - 1 && bo[ny][nx] == 0 && bo[ny-1][nx] == -1){
                        bo[ny][nx] = 2;
                        bo[ny-1][nx] = 2;
                        que.push(T(ny-1, nx, cost+1));
                    }
                    if(i == 2 && 0 <= nx - 1 && bo[ny][nx] == 0 && bo[ny][nx-1] == -1){
                        bo[ny][nx] = 2;
                        bo[ny][nx-1] = 2;
                        que.push(T(ny, nx-1, cost+1));
                    }
                    if(i == 3 && ny + 1 < 2 * h - 1 && bo[ny][nx] == 0 && bo[ny+1][nx] == -1){
                        bo[ny][nx] = 2;
                        bo[ny+1][nx] = 2;
                        que.push(T(ny+1, nx, cost+1));
                    }
                }
            }
        }

        cout << 0 << endl;
        END:;
    }
}