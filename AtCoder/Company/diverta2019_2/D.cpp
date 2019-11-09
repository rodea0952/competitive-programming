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

    ll n; cin>>n;
    ll ga, sa, ba; cin>>ga>>sa>>ba;
    ll gb, sb, bb; cin>>gb>>sb>>bb;

    // dp[i] := 前のドングリ数が i のとき、今のドングリ数の最大値

    // A -> B
    vector<ll> dp1(n+1);
    iota(dp1.begin(), dp1.end(), 0LL);
    for(int i=0; i<=n; i++){
        if(i - ga >= 0) chmax(dp1[i], dp1[i - ga] + gb);
        if(i - sa >= 0) chmax(dp1[i], dp1[i - sa] + sb);
        if(i - ba >= 0) chmax(dp1[i], dp1[i - ba] + bb);
    }

    // B -> A
    n = dp1[n];
    vector<ll> dp2(n+1);
    iota(dp2.begin(), dp2.end(), 0LL);
    for(int i=0; i<=n; i++){
        if(i - gb >= 0) chmax(dp2[i], dp2[i - gb] + ga);
        if(i - sb >= 0) chmax(dp2[i], dp2[i - sb] + sa);
        if(i - bb >= 0) chmax(dp2[i], dp2[i - bb] + ba);
    }

    cout << dp2[n] << endl;

    return 0;
}
