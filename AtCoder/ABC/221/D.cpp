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

    int n; cin >> n;
    vector<P> x;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        x.emplace_back(a, 1);
        x.emplace_back(a + b, -1);
    }

    sort(all(x));

    int cnt = 0;
    vector<int> ans(n + 1, 0);
    for(int i=0; i<x.size()-1; i++){
        cnt += x[i].second;
        ans[cnt] += x[i + 1].first - x[i].first;
    }

    for(int i=1; i<=n; i++){
        cout << ans[i] << " \n"[i == n];
    }

    return 0;
}