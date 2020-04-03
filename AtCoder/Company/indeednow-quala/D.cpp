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

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int h, w;
map<vector<vector<int>>, int> mi[2];

void dfs(vector<vector<int>> &cur, int cnt, int cy, int cx, int idx){
    if(12 < cnt) return ;
    if(mi[idx].count(cur) && mi[idx][cur] < cnt) return ;

    mi[idx][cur] = cnt;

    for(int i=0; i<4; i++){
        int ny = cy + dy[i], nx = cx + dx[i];
        if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;

        swap(cur[cy][cx], cur[ny][nx]);
        dfs(cur, cnt + 1, ny, nx, idx);
        swap(cur[cy][cx], cur[ny][nx]);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>h>>w;
    vector<vector<int>> c(h, vector<int>(w));
    int sy, sx;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>c[i][j];
            if(c[i][j] == 0) sy = i, sx = j;
        }
    }

    vector<vector<int>> goal(h, vector<int>(w));
    int cnt = 1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) goal[i][j] = cnt++;
    }
    goal[h-1][w-1] = 0;

    dfs(c, 0, sy, sx, 0);
    dfs(goal, 0, h - 1, w - 1, 1);

    int ans = 24;
    for(auto i:mi[0]){
        if(mi[1].count(i.first)){
            chmin(ans, i.second + mi[1][i.first]);
        }
    }

    cout << ans << endl;

    return 0;
}