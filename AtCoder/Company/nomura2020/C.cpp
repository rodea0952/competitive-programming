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
    n++;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<ll> dep_ub(n);
    ll lb = a[n-1], ub = a[n-1];
    dep_ub[n-1] = ub;
    for(int i=n-2; i>=0; i--){
        lb = (lb + 1) / 2 + a[i];
        ub = ub + a[i];
        dep_ub[i] = ub;
    }

    if(!(lb <= 1 && 1 <= ub)){
        cout << -1 << endl;
        return 0;
    }

    ll cur = 1, ans = 1;
    for(int i=1; i<n; i++){
        cur = min(cur * 2, dep_ub[i]);
        ans += cur;
        cur -= a[i];
    }

    cout << ans << endl;

    return 0;
}