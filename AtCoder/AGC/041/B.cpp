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

    ll n, m, v, p; cin>>n>>m>>v>>p;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    sort(a.begin(), a.end());

    // (ng, ok]
    int ng = -1, ok = n - 1;
    while(ok - ng > 1){
        int mid = (ng + ok) / 2;

        ll base = a[mid] + m;

        if((n - p) <= mid){
            ok = mid;
            continue;
        }

        if(base < a[(n - p)]){
            ng = mid;
            continue;
        }

        // 上位 P - 1 問、a[mid] より低い mid 問、a[mid] に M 人が 1 票入れる
        ll rest = v - (p - 1) - mid - 1;

        ll sum = 0;
        for(int i=0; i<n; i++){
            if(mid < i && i <= n - p && a[i] < base){
                sum += base - a[i];
            }
        }

        if(sum < rest * m) ng = mid;
        else ok = mid;
    }

    cout << (n - ok) << endl;

    return 0;
}