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

// dp2[i][j] := 数 j を i 分割する総数
vector<vector<ll>> dp2(1010, vector<ll>(1010, 0));

void partition_function(){
    dp2[0][0] = 1;
    for(int i=1; i<=1005; i++){
        for(int j=0; j<=1005; j++){
            if(0 <= j - i){
                (dp2[i][j] = dp2[i-1][j] + dp2[i][j-i]) %= MOD;
            }
            else{
                dp2[i][j] = dp2[i-1][j];
            }
        }
    }

    return ;
}

ll solve(vector<int> &kill, vector<int> &death){
    int n = kill.size();
    vector<int> same_kill(n, 0);
    int cnt = 0;
    for(int i=0; i<n; i++){
        int num = kill[i];
        while(i < n && num == kill[i]){
            same_kill[cnt]++;
            i++;
        }
        cnt++;
        i--;
    }

    int death_sum = accumulate(death.begin(), death.end(), 0);

    n = cnt;
    vector<vector<ll>> dp(n+1, vector<ll>(death_sum+1, 0));

    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=death_sum; j++){
            for(int k=0; k<=death_sum-j; k++){
                (dp[i+1][j+k] += dp[i][j] * dp2[same_kill[i]][k]) %= MOD;
            }
        }
    }

    return dp[cnt][death_sum];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    partition_function();

    ll ansA = solve(a, b);
    ll ansB = solve(b, a);

    cout << (ansA * ansB) % MOD << endl;
}