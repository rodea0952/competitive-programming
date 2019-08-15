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

vector<vector<int>> sumb(4002, vector<int>(4002, 0));

int get(int y, int x, int k){
    return sumb[y+k-1][x+k-1] + sumb[y-1][x-1] - sumb[y+k-1][x-1] - sumb[y-1][x+k-1];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin>>n>>k;
    vector<vector<int>> black(2*k, vector<int>(2*k, 0));
    for(int i=0; i<n; i++){
        int x, y; char c; cin>>x>>y>>c;
        if(c == 'W') y += k;

        black[y%(2*k)][x%(2*k)]++;
    }

    for(int i=0; i<4*k; i++){
        for(int j=0; j<4*k; j++){
            sumb[i+1][j+1] = sumb[i+1][j] + black[i%(2*k)][j%(2*k)];
        }
    }

    for(int i=0; i<4*k; i++){
        for(int j=0; j<4*k; j++){
            sumb[j+1][i+1] += sumb[j][i+1];
        }
    }

    int ans = 0;
    for(int i=1; i<=2*k; i++){
        for(int j=1; j<=2*k; j++){
            int val = get(i, j, k) + get(i + k, j + k, k);
            chmax(ans, val);
        }
    }

    cout << ans << endl;
}