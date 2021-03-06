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

int LIS(vector<int> &a){
    // dp[i] := 長さが i+1 であるような増加部分列における最終要素の最小値
    int n = a.size();
    vector<int> dp(n, inf);
    for(int i=0; i<n; i++){
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }

    return lower_bound(dp.begin(), dp.end(), inf) - dp.begin();
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<P> wh(n);
    for(int i=0; i<n; i++){
        int w, h; cin>>w>>h;
        wh[i] = P(w, -h);
    }

    sort(wh.begin(), wh.end());

    vector<int> v;
    for(int i=0; i<n; i++){
        v.emplace_back(-wh[i].second);
    }

    cout << LIS(v) << endl;

    return 0;
}