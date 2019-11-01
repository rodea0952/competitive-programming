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

    ll n, k; cin>>n>>k;
    vector<ll> a(n), f(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>f[i];
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<ll>());

    ll ng = -1, ok = INF;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;

        ll sum = 0;
        for(int i=0; i<n; i++){
            ll num = (mid / f[i]);
            sum += max(0LL, a[i] - num);
        }

        if(sum <= k) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}
