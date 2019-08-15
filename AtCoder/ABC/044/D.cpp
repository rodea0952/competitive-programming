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

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

ll f(ll b, ll n){
    if(n < b) return n;
    else return f(b, n / b) + (n % b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, s; cin>>n>>s;

    if(n == s){
        cout << n + 1 << endl;
        return 0;
    }

    for(ll b=2; b*b<=n; b++){
        if(f(b, n) == s){
            cout << b << endl;
            return 0;
        }
    }

    // n = α * b + β
    // s = α + β
    ll ans = INF;
    for(ll alpha=1; alpha*alpha<=n; alpha++){
        ll b = (n - s) / alpha + 1;
        
        if(b < 2) continue;
        if(f(b, n) != s) continue;

        chmin(ans, b);
    }

    cout << (ans == INF ? -1 : ans) << endl;
}
