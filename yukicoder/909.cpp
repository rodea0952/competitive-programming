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
    vector<ll> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i];
    for(int i=0; i<n; i++) cin>>y[i];

    ll min_xy = INF;
    for(int i=0; i<n; i++){
        chmin(min_xy, x[i] + y[i]);
    }

    vector<ll> ans(n);
    ll pos0 = 1e9, posN2 = 1e9 + min_xy;

    for(int i=0; i<n; i++){
        if(x[i] < y[i]){
            ans[i] = pos0 + x[i];
        }
        else{
            ans[i] = posN2 - y[i];
        }
    }

    cout << min_xy << endl;
    cout << pos0 << endl;
    for(int i=0; i<n; i++) cout << ans[i] << endl;
    cout << posN2 << endl;

    return 0;
}