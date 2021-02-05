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

    int h, w, n, m; cin>>h>>w>>n>>m;
    vector<vector<int>> squ(h, vector<int>(w, 0));
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b; a--, b--;
        squ[a][b] = 1;
    }
    for(int i=0; i<m; i++){
        int c, d; cin>>c>>d; c--, d--;
        squ[c][d] = -1;
    }

    for(int i=0; i<h; i++){
        int l = 0;
        for(int j=0; j<w; j++){
            if(squ[i][j] == 2) continue;
            if(squ[i][j] == 1) l = 2;
            else if(squ[i][j] == -1) l = 0;
            else squ[i][j] = l;
        }
        l = 0;
        for(int j=w-1; j>=0; j--){
            if(squ[i][j] == 2) continue;
            if(squ[i][j] == 1) l = 2;
            else if(squ[i][j] == -1) l = 0;
            else squ[i][j] = l;
        }
    }

    for(int j=0; j<w; j++){
        int l = 0;
        for(int i=0; i<h; i++){
            if(squ[i][j] == 2) continue;
            if(squ[i][j] == 1) l = 2;
            else if(squ[i][j] == -1) l = 0;
            else squ[i][j] = l;
        }
        l = 0;
        for(int i=h-1; i>=0; i--){
            if(squ[i][j] == 2) continue;
            if(squ[i][j] == 1) l = 2;
            else if(squ[i][j] == -1) l = 0;
            else squ[i][j] = l;
        }
    }

    int ans = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            ans += squ[i][j] > 0;
        }
    }

    cout << ans << endl;

    return 0;
}