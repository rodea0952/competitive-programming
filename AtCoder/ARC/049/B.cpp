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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> x(n), y(n), c(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i]>>c[i];

    double ng = 0, ok = 1e9;
    for(int i=0; i<100; i++){
        double mid = (ng + ok) / 2;

        bool valid = true;
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                int dist_y = abs(y[j] - y[k]);
                if(dist_y > mid / c[j] + mid / c[k]) valid = false;
                int dist_x = abs(x[j] - x[k]);
                if(dist_x > mid / c[j] + mid / c[k]) valid = false;
            }
        }

        if(valid) ok = mid;
        else ng = mid;
    }

    printf("%.10f\n", ok);

    return 0;
}