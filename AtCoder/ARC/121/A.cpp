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

    int n; cin>>n;
    vector<P> x(n), y(n);
    for(int i=0; i<n; i++){
        int cx, cy; cin>>cx>>cy;
        x[i] = P(cx, i);
        y[i] = P(cy, i);
    }

    sort(all(x));
    sort(all(y));

    int ans = max({x[n - 2].first - x[0].first, x[n - 1].first - x[1].first, y[n - 2].first - y[0].first, y[n - 1].first - y[1].first});
    if(!((x[0].second == y[0].second && x[n - 1].second == y[n - 1].second) || (x[0].second == y[n - 1].second && x[n - 1].second == y[0].second))){
        ans = max(ans, min(x[n - 1].first - x[0].first, y[n - 1].first - y[0].first));
    }

    cout << ans << endl;

    return 0;
}