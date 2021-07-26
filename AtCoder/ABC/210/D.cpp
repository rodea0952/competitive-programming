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
using T = tuple<ll, ll, ll, ll>;

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

    int h, w; ll c; cin >> h >> w >> c;
    vector<vector<ll>> a(h, vector<ll>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
        }
    }

    ll ans = INF;
    for(int rev=0; rev<2; rev++){
        vector<vector<ll>> mi(h, vector<ll>(w, INF));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(i) mi[i][j] = min(mi[i][j], mi[i - 1][j]);
                if(j) mi[i][j] = min(mi[i][j], mi[i][j - 1]);
                ans = min(ans, a[i][j] + c * (i + j) + mi[i][j]);
                mi[i][j] = min(mi[i][j], a[i][j] - c * (i + j));
            }
        }
        reverse(a.begin(), a.end());
    }

    cout << ans << endl;

    return 0;
}