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

    int n, d; cin >> n >> d;
    vector<int> l(n), r(n);
    for(int i=0; i<n; i++) cin >> l[i] >> r[i];

    vector<P> lr(n);
    for(int i=0; i<n; i++){
        lr[i] = P(l[i], r[i]);
    }

    sort(all(lr), [](P& a, P& b){return a.second < b.second;});

    int ans = 0, pre_r = -inf;
    for(auto i : lr){
        if(pre_r + d - 1 < i.first){
            ans++;
            pre_r = i.second;
        }
    }

    cout << ans << endl;

    return 0;
}