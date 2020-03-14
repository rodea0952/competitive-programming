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

    ll n, c; cin>>n>>c;

    vector<vector<int>> pos(c);
    for(int i=0; i<c; i++) pos[i].emplace_back(-1);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        a--;
        pos[a].emplace_back(i);
    }
    for(int i=0; i<c; i++) pos[i].emplace_back(n);

    for(int i=0; i<c; i++){
        ll ans = n * (n + 1) / 2;
        for(int j=0; j+1<pos[i].size(); j++){
            int cur = pos[i][j], nxt = pos[i][j+1];
            ll dist = nxt - cur;
            ans -= dist * (dist - 1) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}