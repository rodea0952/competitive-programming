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

    int q; cin>>q;
    while(q--){
        ll n, i, j; cin>>n>>i>>j;
        ll mi = min({i, j, n - 1 - i, n - 1 - j});
        ll ans = n * n - (n - 2 * mi) * (n - 2 * mi);
        n -= 2 * mi;
        i -= mi;
        j -= mi;

        if(i == 0) ans += j;
        else if(j == n - 1) ans += (n - 1) + i;
        else if(i == n - 1) ans += 2 * (n - 1) + (n - 1 - j);
        else ans += 3 * (n - 1) + (n - 1 - i);

        cout << ans << endl;
    }

    return 0;
}