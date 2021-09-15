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

    int n; cin >> n;
    vector<int> x(n), y(n);
    vector<P> xy(n);
    set<P> point;
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
        xy[i] = P(x[i], y[i]);
        point.emplace(x[i], y[i]);
    }

    sort(all(xy));

    for(int i=0; i<n; i++){
        tie(x[i], y[i]) = xy[i];
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x1 = x[i], y1 = y[i];
            int x3 = x[j], y3 = y[j];
            if(!(x1 < x3)) continue;
            if(!(y1 < y3)) continue;
            int x2 = x1, y2 = y3, x4 = x3, y4 = y1;
            if(point.count(P(x2, y2)) && point.count(P(x4, y4))) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}