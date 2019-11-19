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

    vector<string> a(10);
    int land = 0;
    for(int i=0; i<10; i++){
        cin>>a[i];
        for(auto j : a[i]){
            land += (j == 'o');
        }
    }

    bool valid = false;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(a[i][j] == 'o') continue;

            int cur = 0;
            auto b = a;
            b[i][j] = 'o';
            queue<P> que;
            que.emplace(i, j);
            vector<vector<bool>> visited(10, vector<bool>(10, false));
            visited[i][j] = true;
            while(que.size()){
                int cy, cx;
                tie(cy, cx) = que.front(); que.pop();
                for(int k=0; k<4; k++){
                    int ny = cy + dy[k], nx = cx + dx[k];
                    if(!(0 <= ny && ny < 10 && 0 <= nx && nx < 10)) continue;
                    if(b[ny][nx] == 'x') continue;
                    if(visited[ny][nx]) continue;

                    cur++;
                    visited[ny][nx] = true;
                    que.emplace(ny, nx);
                }
            }

            if(cur == land) valid = true;
        }
    }

    cout << (valid ? "YES" : "NO") << endl;

    return 0;
}