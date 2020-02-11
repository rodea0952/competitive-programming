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

int dp[110][2][5];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string n; cin>>n;
    int sz = n.size();
    int k; cin>>k;

    dp[0][0][0] = 1;
    for(int i=0; i<sz; i++){
        int cur = n[i] - '0';
        // 未満フラグ
        for(int smaller=0; smaller<2; smaller++){
            // 0 でない数が既に j 個出た
            for(int j=0; j<=k; j++){
                for(int x=0; x<=(smaller ? 9 : cur); x++){
                    dp[i+1][smaller || x < cur][j + (x != 0)] += dp[i][smaller][j];
                }
            }
        }
    }

    cout << dp[sz][0][k] + dp[sz][1][k] << endl;

    return 0;
}