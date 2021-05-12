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

    int n, q; cin>>n>>q;
    vector<ll> x(n), y(n);
    vector<ll> cx(n), cy(n);
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
        cx[i] = x[i] - y[i], cy[i] = x[i] + y[i];
    }

    sort(all(cx));
    sort(all(cy));

    while(q--){
        int idx; cin>>idx; idx--;
        ll qx = x[idx] - y[idx], qy = x[idx] + y[idx];
        cout << max({cx.back() - qx, qx - cx[0], cy.back() - qy, qy - cy[0]}) << endl; 
    }

    return 0;
}