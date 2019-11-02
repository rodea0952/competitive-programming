#pragma GCC optimize("O3")
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
#include <chrono>
#include <time.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, b; cin>>n>>m>>b;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    int gy, gx; cin>>gy>>gx;
    queue<P> que;
    que.emplace(gy, gx);
    grid[gy][gx] = 'o';
    vector<int> ry(m), rx(m);
    vector<char> c(m);
    for(int i=0; i<m; i++){
        cin>>ry[i]>>rx[i]>>c[i];
    }
    for(int i=0; i<b; i++){
        int by, bx; cin>>by>>bx;
        grid[by][bx] = 'x';
    }

    vector<vector<int>> dist(n, vector<int>(n, inf));
    dist[gy][gx] = 0;
    set<tuple<int, int, char>> ans;
    while(que.size()){
        int cy, cx;
        tie(cy, cx) = que.front(); que.pop();
        
        // up
        int ny = (cy - 1 + n) % n, nx = cx;
        if(dist[cy][cx] + 1 < dist[ny][nx] && grid[ny][nx] == '.'){
            dist[ny][nx] = dist[cy][cx] + 1;
            grid[ny][nx] = 'D';
            ans.emplace(ny, nx, grid[ny][nx]);
            que.emplace(ny, nx);
        }

        // down
        ny = (cy + 1) % n, nx = cx;
        if(dist[cy][cx] + 1 < dist[ny][nx] && grid[ny][nx] == '.'){
            dist[ny][nx] = dist[cy][cx] + 1;
            grid[ny][nx] = 'U';
            ans.emplace(ny, nx, grid[ny][nx]);
            que.emplace(ny, nx);
        }

        // left
        ny = cy, nx = (cx - 1 + n) % n;
        if(dist[cy][cx] + 1 < dist[ny][nx] && grid[ny][nx] == '.'){
            dist[ny][nx] = dist[cy][cx] + 1;
            grid[ny][nx] = 'R';
            ans.emplace(ny, nx, grid[ny][nx]);
            que.emplace(ny, nx);
        }

        // right
        ny = cy, nx = (cx + 1) % n;
        if(dist[cy][cx] + 1 < dist[ny][nx] && grid[ny][nx] == '.'){
            dist[ny][nx] = dist[cy][cx] + 1;
            grid[ny][nx] = 'L';
            ans.emplace(ny, nx, grid[ny][nx]);
            que.emplace(ny, nx);
        }
    }
    
    int A = 0, B, C = 0;
    vector<vector<bool>> need_panel(n, vector<bool>(n, false));
    for(int i=0; i<m; i++){
        queue<tuple<int, int, char>> que2;
        que2.emplace(ry[i], rx[i], c[i]);
        while(que2.size()){
            int cy, cx; char cdir;
            tie(cy, cx, cdir) = que2.front(); que2.pop();
            if(grid[cy][cx] == 'o') {A++; break;}

            int ny = cy, nx = cx; char ndir = cdir;
            if(grid[cy][cx] == 'U'){
                ny--, ndir = 'U';
                if(cdir != ndir) need_panel[cy][cx] = true;
            }
            else if(grid[cy][cx] == 'D'){
                ny++, ndir = 'D';
                if(cdir != ndir) need_panel[cy][cx] = true;
            }
            else if(grid[cy][cx] == 'L'){
                nx--, ndir = 'L';
                if(cdir != ndir) need_panel[cy][cx] = true;
            }
            else if(grid[cy][cx] == 'R'){
                nx++, ndir = 'R';
                if(cdir != ndir) need_panel[cy][cx] = true;
            }
            else{
                continue;
            }

            ny = (ny + n) % n;
            nx = (nx + n) % n;

            que2.emplace(ny, nx, ndir);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 'x') continue;
            if(grid[i][j] == 'o') continue;

            if(need_panel[i][j]) C++;
            else{
                char cc = grid[i][j];
                ans.erase(make_tuple(i, j, cc));
            }
        }
    }

    B = ans.size();
    int cur_score = 1000 * A - 10 * B + C;    

    cout << ans.size() << endl;
    for(auto i : ans){
        int ansy, ansx;
        char ansc;
        tie(ansy, ansx, ansc) = i;
        cout << ansy << " " << ansx << " " << ansc << endl;
    }

    // cout << cur_score << endl;
    
    return 0;
}
