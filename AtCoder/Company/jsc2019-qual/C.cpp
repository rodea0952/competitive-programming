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

int a[510][510];

// [lb, ub]
void rec(int lb, int ub, int depth){
    if(lb == ub) return ;
    int mid = (lb + ub) / 2;

    // [lb, mid] ↔ [mid + 1, ub]
    for(int i=lb; i<=mid; i++){
        for(int j=mid+1; j<=ub; j++){
            a[i][j] = depth;
        }
    }

    rec(lb, mid, depth + 1);
    rec(mid + 1, ub, depth + 1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;

    rec(1, n, 1);

    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            cout << a[i][j] << " \n"[j == n];
        }
    }
}