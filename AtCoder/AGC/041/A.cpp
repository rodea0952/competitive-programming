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

    ll n, a, b; cin>>n>>a>>b;

    if((b - a) % 2 == 0){
        cout << (b - a) / 2 << endl;
    }
    else{
        ll ans = min(b - 1, n - a);
        // A が卓 1 に行く
        ll Aleft = a;
        ll Bleft = b - Aleft;
        chmin(ans, Aleft + (Bleft - 1) / 2);

        // B が卓 N に行く
        ll Bright = (n - b + 1);
        ll Aright = a + Bright;
        chmin(ans, Bright + (n - Aright) / 2);
        
        cout << ans << endl;
    }

    return 0;
}