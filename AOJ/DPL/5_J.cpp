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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// dp[i][j] := 数 j を i 分割する総数
vector<vector<ll>> dp(1010, vector<ll>(1010, 0));
void part_init(){
    dp[0][0] = 1;
    for(int i=1; i<=1005; i++){
        for(int j=0; j<=1005; j++){
            if(0 <= j - i){
                (dp[i][j] = dp[i-1][j] + dp[i][j-i]) %= MOD;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin>>n>>k;

    part_init();

    cout << dp[k][n] << endl;


    return 0;
}