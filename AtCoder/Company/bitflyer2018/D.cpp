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

    int h, w, n, m; cin>>h>>w>>n>>m;

    vector<vector<int>> sum(2*n+10, vector<int>(2*m+10, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin>>c;
            if(c == '#'){
                int si = i;
                int sj = j;
                int ti = min(2*n+1, h) - n + i + 1;
                int tj = min(2*m+1, w) - m + j + 1;

                sum[si][sj]++;
                sum[ti][sj]--;
                sum[si][tj]--;
                sum[ti][tj]++;
            }
        }
    }

    for(int i=0; i<min(h, 2*n+5); i++){
        for(int j=0; j<min(w, 2*m+5); j++){
            sum[i][j+1] += sum[i][j];
        }
    }

    for(int i=0; i<min(w, 2*m+5); i++){
        for(int j=0; j<min(h, 2*n+5); j++){
            sum[j+1][i] += sum[j][i];
        }
    }

    ll ans = 0;
    for(int i=0; i<min(h, 2*n+1); i++){
        for(int j=0; j<min(w, 2*m+1); j++){
            ll val = !!sum[i][j];

            if(i == n && 2 * n < h) val *= (h - 2 * n);
            if(j == m && 2 * m < w) val *= (w - 2 * m);
            
            ans += val;
        }
    }

    cout << ans << endl;
}