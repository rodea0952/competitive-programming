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

    vector<vector<int>> dp(h, vector<int>(w, inf));
    if(s[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    queue<P> que;
    que.emplace(0, 0);
    while(que.size()){
        int cy, cx; tie(cy, cx) = que.front(); que.pop();
        
        for(int i=0; i<2; i++){
            int ny = cy + dy[i], nx = cx + dx[i];
            if(!(ny < h && nx < w)) continue;

            int cost = 0;
            if(s[cy][cx] == '.' && s[ny][nx] == '#') cost = 1;

            if(dp[ny][nx] > dp[cy][cx] + cost){
                dp[ny][nx] = dp[cy][cx] + cost;
                que.emplace(ny, nx);
            }
        }
    }

    cout << dp[h-1][w-1] << endl;

    return 0;
}