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

    double a, b, c, d; cin>>a>>b>>c>>d;

    double D = (a - c) * (a - c) - 8 * (b - d);

    if(D < 0){
        cout << "No" << endl;
    }
    else if(D == 0){
        cout << "Yes" << endl;
    }
    else{
        double x1 = (-(a - c) + sqrt(D)) / 4;
        double x2 = (-(a - c) - sqrt(D)) / 4;

        double p = x1 + x2 + a, q = -x1 * x2 + b;

        printf("%.20f %.20f\n", p, q);
    }

    return 0;
}