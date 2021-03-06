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
    vector<int> l(n, inf + 1), r(n, -inf - 1);
    for(int i=0; i<n; i++){
        int x, c; cin>>x>>c; c--;
        chmin(l[c], x);
        chmax(r[c], x);
    }

    vector<P> lr;
    lr.emplace_back(0, 0);
    for(int i=0; i<n; i++){
        if(l[i] != inf + 1) lr.emplace_back(l[i], r[i]);
    }
    lr.emplace_back(0, 0);

    vector<ll> dp(2, 0);
    for(int i=1; i<lr.size(); i++){
        vector<ll> ndp(2, INF);
        int cl = lr[i].first, cr = lr[i].second;
        for(int j=0; j<2; j++){
            int pre = j ? lr[i - 1].second : lr[i - 1].first;
            chmin(ndp[0], dp[j] + abs(pre - cr) + (cr - cl));
            chmin(ndp[1], dp[j] + abs(pre - cl) + (cr - cl));
        }
        dp = ndp;
    }

    cout << dp[0] << endl;

    return 0;
}