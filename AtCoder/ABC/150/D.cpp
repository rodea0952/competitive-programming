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
    ll m; cin>>m;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    ll l = 1;
    for(int i=0; i<n; i++){
        a[i] /= 2;
        l = (l / __gcd(l, a[i]) * a[i]);
        if(m < l){
            cout << 0 << endl;
            return 0;
        }
    }

    for(int i=0; i<n; i++){
        ll div = l / a[i];
        if(div % 2 == 0){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (m / l - m / (2 * l)) << endl;

    return 0;
}
