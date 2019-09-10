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

    int h, w, k; cin>>h>>w>>k;
    vector<string> a(h);
    vector<P> v;
    queue<T> que;
    for(int i=0; i<h; i++){
        cin>>a[i];
        for(int j=0; j<w; j++){
            if(a[i][j] == 'S'){
                a[i][j] = '#';
                v.emplace_back(i, j);
                que.emplace(i, j, 0);
            }
        }
    }

    while(que.size()){
        int cy, cx, cnt;
        tie(cy, cx, cnt) = que.front(); que.pop();

        if(cnt == k) continue;

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
            
            if(a[ny][nx] == '.'){
                a[ny][nx] = '#';
                v.emplace_back(ny, nx);
                que.emplace(ny, nx, cnt + 1);
            }
        }
    }

    int ans = inf;
    for(auto cur : v){
        int cy, cx;
        tie(cy, cx) = cur;

        int sum = 1;
        int disth = min(cy, h - cy - 1);
        int distw = min(cx, w - cx - 1);
        sum += (min(disth, distw) + k - 1) / k;
        
        chmin(ans, sum);
    }

    cout << ans << endl;
}
