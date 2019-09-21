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

    int n; cin>>n;
    vector<int> l(n), r(n);
    for(int i=0; i<n; i++) cin>>l[i]>>r[i];
    sort(l.begin(), l.end(), greater<int>());
    sort(r.begin(), r.end());

    ll ans = 0;

    // start from left
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += l[i];
        chmax(ans, sum);
        sum -= r[i];
        chmax(ans, sum);
    }

    // start from right
    sum = 0;
    for(int i=0; i<n; i++){
        sum -= r[i];
        chmax(ans, sum);
        sum += l[i];
        chmax(ans, sum);
    }

    cout << ans * 2 << endl;

    return 0;
}