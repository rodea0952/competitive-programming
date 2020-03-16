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

    int h, w, k; cin>>h>>w>>k;
    k--;

    if(w == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<vector<ll>> dp(h+1, vector<ll>(w, 0));
    dp[0][0] = 1;
    for(int i=0; i<h; i++){
        for(int bit=0; bit<(1<<(w-1)); bit++){
            bool valid = true;
            for(int j=0; j+1<w-1; j++){
                if((bit & (1 << j)) && (bit & (1 << (j + 1)))) valid = false;
            }

            if(!valid) continue;

            // 横棒があるとき
            for(int j=0; j<w-1; j++){
                if(bit & (1 << j)){
                    // 左側に降りる
                    dp[i+1][j] += dp[i][j+1];
                    dp[i+1][j] %= MOD;

                    // 右側に降りる
                    dp[i+1][j+1] += dp[i][j];
                    dp[i+1][j+1] %= MOD;
                }
            }

            // 横棒がないとき、下に流れる
            if(!(bit & 1)){
                dp[i+1][0] += dp[i][0];
                dp[i+1][0] %= MOD;
            }

            for(int j=0; j+1<w-1; j++){
                if(!(bit & (1 << j)) && !(bit & (1 << (j + 1)))){
                    dp[i+1][j+1] += dp[i][j+1];
                    dp[i+1][j+1] %= MOD;
                }
            }

            if(!(bit & (1 << (w - 2)))){
                dp[i+1][w-1] += dp[i][w-1];
                dp[i+1][w-1] %= MOD;
            }
        }
    }

    cout << dp[h][k] << endl;

    return 0;
}