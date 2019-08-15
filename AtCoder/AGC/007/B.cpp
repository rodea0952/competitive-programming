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
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin>>p[i];
        p[i]--;
    }

    int base = 30000;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        a[i] = 30000 * (i + 1);
        b[i] = 30000 * (n - i);
    }

    for(int i=0; i<n; i++){
        a[p[i]] += i;
    }

    for(int i=0; i<n; i++){
        cout << a[i] << " \n"[i == n-1];
    }
    for(int i=0; i<n; i++){
        cout << b[i] << " \n"[i == n-1];
    }
}