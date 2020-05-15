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

    int n, m, x; cin>>n>>m>>x;

    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++){
        cin>>c[i];
        for(int j=0; j<m; j++) cin>>a[i][j];
    }

    ll mi = INF;
    for(int bit=0; bit<(1<<n); bit++){
        ll ans = 0;
        vector<int> sum(m, 0);
        for(int i=0; i<n; i++){
            if(bit & (1 << i)){
                ans += c[i];
                for(int j=0; j<m; j++) sum[j] += a[i][j];
            }
        }

        bool valid = true;
        for(int i=0; i<m; i++){
            if(sum[i] < x) valid = false;
        }

        if(valid) chmin(mi, ans);
    }

    cout << (mi == INF ? -1 : mi) << endl;

    return 0;
}