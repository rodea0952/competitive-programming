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

    int n; cin>>n;
    vector<ll> y(n);
    for(int i=0; i<n; i++) cin>>y[i];

    sort(all(y));

    if(y[0] == y[n-1]){
        cout << 1 << endl;
        return 0;
    }

    vector<ll> ysum(n+1, 0);
    for(int i=0; i<n; i++){
        ysum[i+1] = ysum[i] + y[i];
    }

    ll ans = INF;
    for(int i=1; i<n; i++){
        ll lhead = ysum[i / 2];
        ll ltail = ysum[i];
        if(i % 2 == 1) ltail -= y[i / 2];
        
        ll rhead = ysum[(i + n) / 2] - ysum[i];
        ll rtail = ysum[n] - ysum[i];
        if((n - i) % 2 == 1) rtail -= y[(i + n) / 2];

        chmin(ans, ltail - lhead * 2 + rtail - rhead * 2);
    }

    cout << ans << endl;

    return 0;
}