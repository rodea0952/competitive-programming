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

    int n, m, p; cin>>n>>m>>p;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int amax = *max_element(all(a));

    vector<int> pdivmax(40, -1);
    for(int i=0; i<n; i++){
        int cnt = 0;
        while(a[i] % p == 0){
            a[i] /= p;
            cnt++;
        }
        chmax(pdivmax[cnt], a[i]);
    }

    vector<ll> dp(1010, 0);
    // dp[i] := 操作回数 i 回のときの x の最大値
    dp[0] = 1;
    for(int i=0; i<1000; i++){
        if(dp[i] == 0) continue;

        if(m < dp[i] * amax){
            cout << i + 1 << endl;
            return 0;
        }

        for(int j=0; j<40; j++){
            if(pdivmax[j] == -1) continue;
            if(i + j + 1 <= 1000) chmax(dp[i + j + 1], dp[i] * pdivmax[j]);
        }
    }

    cout << -1 << endl;

    return 0;
}