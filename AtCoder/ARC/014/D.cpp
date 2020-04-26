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

    int all, n, m; cin>>all>>n>>m;
    vector<int> l(n);
    for(int i=0; i<n; i++) cin>>l[i];

    int head = l[0] - 1, tail = all - l.back();
    vector<int> lgap(n-1);
    for(int i=0; i+1<n; i++){
        lgap[i] = l[i+1] - l[i] - 1;
    }

    sort(all(lgap));

    vector<int> lgapsum(n, 0);
    for(int i=0; i+1<n; i++){
        lgapsum[i+1] = lgapsum[i] + lgap[i];
    }

    while(m--){
        int x, y; cin>>x>>y;

        ll add = x + y;
        int idx = upper_bound(all(lgap), add) - lgap.begin();

        ll sub = lgapsum[n-1] - lgapsum[idx];
        sub -= add * ((n - 1) - idx);

        ll subhead = max(0, head - x);
        ll subtail = max(0, tail - y);

        cout << all - (sub + subhead + subtail) << endl;
    }

    return 0;
}