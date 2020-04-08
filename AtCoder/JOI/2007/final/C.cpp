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
    set<P> exist;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
        exist.emplace(x[i], y[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x3 = x[i] + abs(y[i] - y[j]);
            int y3 = y[i] + abs(x[i] - x[j]);

            int x4 = x[j] + abs(y[i] - y[j]);
            int y4 = y[j] + abs(x[i] - x[j]);

            if(exist.count(P(x3, y3)) && exist.count(P(x4, y4))){
                chmax(ans, abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]));
            }

            int x5 = x[i] - abs(y[i] - y[j]);
            int y5 = y[i] - abs(x[i] - x[j]);

            int x6 = x[j] - abs(y[i] - y[j]);
            int y6 = y[j] - abs(x[i] - x[j]);

            if(exist.count(P(x5, y5)) && exist.count(P(x6, y6))){
                chmax(ans, abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]));
            }
        }
    }

    cout << ans << endl;    

    return 0;
}