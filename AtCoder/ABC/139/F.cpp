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
    vector<tuple<double, double, double>> points;
    for(int i=0; i<n; i++){
        double x, y; cin>>x>>y;
        double theta = atan2(y, x);
        points.emplace_back(theta, y, x);
        points.emplace_back(theta + 2 * pi, y, x);
    }

    sort(points.begin(), points.end());

    double ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<2*n && j<i+n; j++){
            double sumy = 0, sumx = 0;
            for(int k=i; k<=j; k++){
                double theta, y, x;
                tie(theta, y, x) = points[k];

                sumy += y;
                sumx += x;
            }

            double dist = sqrt(sumx * sumx + sumy * sumy);
            chmax(ans, dist);
        }
    }

    printf("%.12f\n", ans);
}