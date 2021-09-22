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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<vector<int>> a(4, vector<int>(4));
    int acnt = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> a[i][j];
            acnt += a[i][j];
        }
    }

    int ans = 0;
    for(int bit=1; bit<(1<<16); bit++){
        vector<vector<int>> cur(6, vector<int>(6, 0));
        int sy = -1, sx = -1;
        for(int i=0; i<16; i++){
            if(bit & (1 << i)){
                cur[i / 4 + 1][i % 4 + 1] = 1;
                sy = i / 4 + 1, sx = i % 4 + 1;
            }
        }

        queue<P> que;
        que.emplace(sy, sx);
        vector<vector<bool>> visited(6, vector<bool>(6, false));
        visited[sy][sx] = true;
        while(que.size()){
            int cy, cx; tie(cy, cx) = que.front(); que.pop();
            for(int i=0; i<4; i++){
                int ny = cy + dy[i], nx = cx + dx[i];
                if(cur[ny][nx] && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    que.emplace(ny, nx);
                }
            }
        }

        int vcnt = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                vcnt += visited[i + 1][j + 1];
            }
        }

        if(vcnt != __builtin_popcount(bit)){
            continue;
        }

        vcnt = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                vcnt += a[i][j] && visited[i + 1][j + 1];
            }
        }

        if(vcnt != acnt){
            continue;
        }

        que.emplace(0, 0);
        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++) visited[i][j] = false;
        }
        visited[0][0] = true;
        while(que.size()){
            int cy, cx; tie(cy, cx) = que.front(); que.pop();
            for(int i=0; i<4; i++){
                int ny = cy + dy[i], nx = cx + dx[i];
                if(!(0 <= ny && ny < 6 && 0 <= nx && nx < 6)) continue;
                if(!cur[ny][nx] && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    que.emplace(ny, nx);
                }
            }
        }

        int need = 6 * 6 - __builtin_popcount(bit);
        vcnt = 0;
        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                vcnt += visited[i][j];
            }
        }

        if(need != vcnt){
            continue;
        }

        ans++;
    }

    cout << ans << endl;

    return 0;
}