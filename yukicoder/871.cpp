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

    int n, k; cin>>n>>k;
    vector<ll> x(n+2), a(n+1);
    x[0] = -INF, x[n+1] = INF;
    for(int i=1; i<=n; i++) cin>>x[i];
    for(int i=1; i<=n; i++) cin>>a[i];

    queue<int> que;
    que.emplace(k);

    int ub = k, lb = k;
    while(que.size()){
        int cur = que.front(); que.pop();

        ll r = x[cur] + a[cur];
        int ridx = upper_bound(all(x), r) - x.begin() - 1;
        for(int i=ub+1; i<=ridx; i++) que.emplace(i);
        chmax(ub, ridx);

        ll l = x[cur] - a[cur];
        int lidx = lower_bound(all(x), l) - x.begin();
        for(int i=lb-1; i>=lidx; i--) que.emplace(i);
        chmin(lb, lidx);
    }

    cout << ub - lb + 1 << endl;

    return 0;
}