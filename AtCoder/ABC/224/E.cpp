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

    int h, w, n;
    cin >> h >> w >> n;
    vector<int> r(n), c(n), a(n);
    map<int, vector<int>> mp;
    for(int i=0; i<n; i++){
        cin >> r[i] >> c[i] >> a[i];
        r[i]--, c[i]--;
        mp[a[i]].emplace_back(i);
    }

    vector<int> hma(h, -1), wma(w, -1);
    vector<int> ans(n, -1);
    for(auto itr=mp.rbegin(); itr!=mp.rend(); itr++){
        for(auto i : itr->second){
            ans[i] = max(hma[r[i]], wma[c[i]]) + 1;
        }

        for(auto i : itr->second){
            chmax(hma[r[i]], ans[i]);
            chmax(wma[c[i]], ans[i]);
        }
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << endl;
    }

    return 0;
}