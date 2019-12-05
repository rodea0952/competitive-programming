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

    ll t1, t2, a1, a2, b1, b2; cin>>t1>>t2>>a1>>a2>>b1>>b2;

    ll p = (a1 - b1) * t1, q = (a2 - b2) * t2;

    if(p > 0) p *= -1, q *= -1;

    if(p + q == 0){
        cout << "infinity" << endl;
    }
    else if(p + q < 0){
        cout << 0 << endl;
    }
    else{
        ll div = -p / (p + q), rem = -p % (p + q);
        if(rem == 0) cout << div * 2 << endl;
        else cout << div * 2 + 1 << endl;
    }

    return 0;
}