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

    int h, w; cin>>h>>w;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    vector<vector<char>> base(h, vector<char>(w, '#'));
    char v0[] = {'6', '3', '1', '4'};
    char v2[] = {'1', '3', '6', '4'};
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(i % 4 == 0) base[i][j] = v0[j % 4];
            if(i % 4 == 1) if(j % 2 == 0) base[i][j] = '2';
            if(i % 4 == 2) base[i][j] = v2[j % 4];
            if(i % 4 == 3) if(j % 2 == 0) base[i][j] = '5';
        }
    }

    queue<P> que;
    que.emplace(0, 0);
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    visited[0][0] = true;
    
    while(que.size()){
        int cy, cx; tie(cy, cx) = que.front(); que.pop();

        if(cy == h - 1 && cx == w - 1){
            cout << "YES" << endl;
            return 0;
        }

        for(int i=0; i<4; i++){
            int ny = cy + dy[i], nx = cx + dx[i];
        
            if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
            if(s[ny][nx] == '#') continue;
            if(s[ny][nx] != base[ny][nx]) continue;
            if(visited[ny][nx]) continue;

            visited[ny][nx] = true;
            que.emplace(ny, nx);
        }
    }

    cout << "NO" << endl;

    return 0;
}