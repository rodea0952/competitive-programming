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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, d; cin>>h>>w>>d;
    int a[h][w];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin>>a[i][j];
    }

    queue<T> que;
    que.emplace(0, 0, 0);
    vector<vector<int>> ans(h, vector<int>(w, -1));
    ans[0][0] = 0;
    while(que.size()){
        int cy, cx, cnt;
        tie(cy, cx, cnt) = que.front(); que.pop();

        if(cnt == d) continue;

        for(int i=0; i<4; i++){
            int ny = cy + dy[i], nx = cx + dx[i];
            if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
            if(ans[ny][nx] != -1) continue;

            int ncnt = cnt + 1;
            ans[ny][nx] = ncnt % 2;
            que.emplace(ny, nx, ncnt);
        }
    }

    int fians = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(ans[i][j] != -1 && ans[i][j] % 2 == d % 2){
                chmax(fians, a[i][j]);
            }
        }
    }

    cout << fians << endl;

    return 0;
}