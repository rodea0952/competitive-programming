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
    vector<ll> a(2*n);
    for(int i=0; i<2*n; i++) cin>>a[i];

    vector<ll> lsum(n+1, 0), rsum(n+1, 0);

    int id = 0;
    for(int i=0; i<2*n; i+=2){
        ll l = a[i] - a[i+1];
        lsum[id+1] = lsum[id] + l;
        id++;
    }

    reverse(a.begin(), a.end());
    id = 0;
    for(int i=0; i<2*n; i+=2){
        ll r = a[i] - a[i+1];
        rsum[id+1] = rsum[id] + r;
        id++;
    }

    ll ans = rsum[n];
    for(int i=0; i<n; i++){
        ll l = lsum[i+1];
        ll r = rsum[n-i-1];
        chmax(ans, l + r);
    }

    cout << ans << endl;

    return 0;
}