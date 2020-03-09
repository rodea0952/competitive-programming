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
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w; cin>>h>>w;
    vector<string> s(h);
    int sy, sx, gy, gx;
    for(int i=0; i<h; i++){
        cin>>s[i];
        for(int j=0; j<w; j++){
            if(s[i][j] == 's') sy = i, sx = j;
            if(s[i][j] == 'g') gy = i, gx = j;
        }
    }

    queue<T> que;
    que.emplace(sy, sx, 0);
    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(3, false)));
    visited[sy][sx][0] = true;

    while(que.size()){
        int cy, cx, cnt;
        tie(cy, cx, cnt) = que.front(); que.pop();

        if(cy == gy && cx == gx){
            cout << "YES" << endl;
            return 0;
        }

        for(int i=0; i<4; i++){
            int ny = cy + dy[i], nx = cx + dx[i];
            if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
            
            if(s[ny][nx] == '#'){
                if(cnt == 2) continue;
                if(!visited[ny][nx][cnt + 1]){
                    visited[ny][nx][cnt + 1] = true;
                    que.emplace(ny, nx, cnt + 1);
                }
            }
            else{
                if(!visited[ny][nx][cnt]){
                    visited[ny][nx][cnt] = true;
                    que.emplace(ny, nx, cnt);
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}