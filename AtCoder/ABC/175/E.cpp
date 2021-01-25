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

    int r, c, k; cin>>r>>c>>k;
    vector<vector<int>> v(r, vector<int>(c, 0));
    for(int i=0; i<k; i++){
        int rr, cc, vv; cin>>rr>>cc>>vv;
        rr--, cc--;
        v[rr][cc] = vv;
    }

    vector<vector<vector<ll>>> dp(r, vector<vector<ll>>(c, vector<ll>(4, -INF)));
    if(v[0][0] != 0) dp[0][0][1] = v[0][0];
    dp[0][0][0] = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            for(int cnt=0; cnt<=3; cnt++){
                if(0 <= j - 1){
                    chmax(dp[i][j][cnt], dp[i][j - 1][cnt]);

                    if(cnt < 3 && v[i][j] != 0){
                        chmax(dp[i][j][cnt + 1], dp[i][j - 1][cnt] + v[i][j]);
                    }
                }

                if(0 <= i - 1){
                    chmax(dp[i][j][0], dp[i - 1][j][cnt]);

                    if(v[i][j] != 0){
                        chmax(dp[i][j][1], dp[i][j][0] + v[i][j]);
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<=3; i++){
        chmax(ans, dp[r - 1][c - 1][i]);
    }

    cout << ans << endl;

    return 0;
}