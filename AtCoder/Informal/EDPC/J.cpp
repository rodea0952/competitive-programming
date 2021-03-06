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

int n;
double dp[310][310][310];

double rec(int x, int y, int z){
    if(dp[x][y][z] != 0) return dp[x][y][z];
    if(x == 0 && y == 0 && z == 0) return 0;

    double ans = 0;
    if(x > 0) ans += rec(x - 1, y, z) * x;
    if(y > 0) ans += rec(x + 1, y - 1, z) * y;
    if(z > 0) ans += rec(x, y + 1, z - 1) * z;
    ans += n;
    ans *= 1. / (x + y + z);

    return dp[x][y][z] = ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    vector<int> cnt(4, 0);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        cnt[a]++;
    }

    double ans = rec(cnt[1], cnt[2], cnt[3]);

    printf("%.10f\n", ans);

    return 0;
}