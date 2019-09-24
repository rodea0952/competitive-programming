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

double todeg(double ang){
    return ang * 180 / pi;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);

    double ans = inf;
    do{
        vector<P> points;
        points.emplace_back(0, 0);
        for(auto i : perm) points.emplace_back(x[i], y[i]);
        points.emplace_back(0, 0);

        double theta = 0, sum = 0;
        for(int i=0; i<=n; i++){
            int dx = points[i+1].first - points[i].first;
            int dy = points[i+1].second - points[i].second;

            double cur_theta = atan2(dy, dx);

            sum += todeg(min(abs(theta - cur_theta), 2 * pi - abs(theta - cur_theta)));
            theta = cur_theta;
        }

        chmin(ans, sum);
    }while(next_permutation(perm.begin(), perm.end()));

    printf("%.10f\n", ans);

    return 0;
}