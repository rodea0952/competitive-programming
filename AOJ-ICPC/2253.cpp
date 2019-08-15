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

int dx[]={1, 0, -1, -1, 0, 1};
int dy[]={0, -1, -1, 0, 1, 1};

int main(){
    while(1){
        int t, n; cin>>t>>n;
        if(t == 0) return 0;

        vector<vector<bool>> visited(200, vector<bool>(200, false));
        for(int i=0; i<n; i++){
            int a, b; cin>>a>>b;
            visited[b + 100][a + 100] = true;
        }

        int sx, sy; cin>>sx>>sy;

        int ans = 1;
        queue<T> que;
        que.push(T(sy + 100, sx + 100, 0));
        visited[sy + 100][sx + 100] = true;
        while(que.size()){
            int cy, cx, cnt;
            tie(cy, cx, cnt) = que.front();
            que.pop();

            for(int i=0; i<6; i++){
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(cnt < t && !visited[ny][nx]){
                    ans++;
                    visited[ny][nx] = true;
                    que.push(T(ny, nx, cnt + 1));
                }
            }
        }

        cout << ans << endl;
    }
}