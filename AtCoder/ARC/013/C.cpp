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
    vector<int> v;
    for(int i=0; i<n; i++){
        int X, Y, Z; cin>>X>>Y>>Z;
        X--, Y--, Z--;
        int m; cin>>m;
        vector<int> x(m), y(m), z(m);
        for(int j=0; j<m; j++) cin>>x[j]>>y[j]>>z[j];
        sort(all(x));
        sort(all(y));
        sort(all(z));

        v.emplace_back(x[0]);
        v.emplace_back(X - x.back());
        v.emplace_back(y[0]);
        v.emplace_back(Y - y.back());
        v.emplace_back(z[0]);
        v.emplace_back(Z - z.back());
    }

    int num = 0;
    for(auto i:v) num ^= i;

    cout << (num != 0 ? "WIN" : "LOSE") << endl;

    return 0;
}