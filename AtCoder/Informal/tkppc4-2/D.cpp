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

    int n, p, q; cin>>n>>p>>q;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    if((p + q) % 2){
        cout << 0 << endl;
        return 0;
    }

    map<int, int> sumcnt;
    for(int i=0; i<n; i++){
        sumcnt[a[i]]++;
    }

    map<int, int> precnt;
    precnt[a[0]]++;

    // y-base
    ll ans = 0;
    for(int i=1; i<n-1; i++){
        ll xcnt = 0, zcnt = 0;
        xcnt = precnt[(p + q) / 2];

        precnt[a[i]]++;

        zcnt = sumcnt[(p - q) / 2 - a[i]] - precnt[(p - q) / 2 - a[i]];

        ans += xcnt * zcnt;
    }

    cout << ans << endl;
}