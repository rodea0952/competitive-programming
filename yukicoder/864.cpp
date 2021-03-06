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

    ll n, k; cin>>n>>k;

    ll ans = 0;
    for(ll i=2; i*i<=k; i++){
        if(k % i == 0){
            ll ac = i, bd = k / i;
            ll A = min(max(0LL, (n - ac / 2) * 2 + !(ac % 2)), ac - 1);
            ll B = min(max(0LL, (n - bd / 2) * 2 + !(bd % 2)), bd - 1);
            if(ac != bd) ans += 2 * A * B;
            else ans += A * B;
        }
    }

    cout << ans << endl;

    return 0;
}