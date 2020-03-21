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

    int n, q; cin>>n>>q;
    vector<P> xw(n);
    for(int i=0; i<n; i++) cin>>xw[i].first>>xw[i].second;
    sort(all(xw));
    vector<ll> x(n), w(n);
    for(int i=0; i<n; i++){
        x[i] = xw[i].first;
        w[i] = xw[i].second;
    }

    vector<ll> xwsum(n+1, 0), wsum(n+1, 0);
    for(int i=0; i<n; i++){
        xwsum[i + 1] = xwsum[i] + x[i] * w[i];
        wsum[i + 1] = wsum[i] + w[i];
    }

    while(q--){
        int X; cin>>X;
        int idx = lower_bound(all(x), X) - x.begin();

        cout << xwsum[n] - 2 * xwsum[idx] + 2 * X * wsum[idx] - X * wsum[n] << endl;
    }

    return 0;
}