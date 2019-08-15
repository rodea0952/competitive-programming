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

    ll i, o, t, j, l, s, z; cin>>i>>o>>t>>j>>l>>s>>z;

    ll ans1 = o * 2;
    ll ans0 = o * 2;

    ll IJL = min({i, j, l});
    if(0 < IJL){
        ans1 += 6;
        ans1 += ((i - 1) / 2) * 4;
        ans1 += ((j - 1) / 2) * 4;
        ans1 += ((l - 1) / 2) * 4;
    }

    ans0 += (i / 2) * 4;
    ans0 += (j / 2) * 4;
    ans0 += (l / 2) * 4;

    cout << max(ans1 / 2, ans0 / 2) << endl;
}