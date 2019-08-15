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
using P = pair<ll, ll>;
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

    int n, m; cin>>n>>m;
    vector<ll> a(n), b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    ll asum = accumulate(a.begin(), a.end(), 0LL);
    ll bsum = accumulate(b.begin(), b.end(), 0LL);

    vector<ll> sanadaA, sanadaB;
    for(int bit=0; bit<(1<<m); bit++){
        if(__builtin_popcount(bit) == 0 || __builtin_popcount(bit) == m) continue;

        ll Ateam = 0;
        for(int i=0; i<m; i++){
            if(bit & (1 << i)) Ateam += b[i];
        }

        ll Bteam = bsum - Ateam;

        if(Ateam > Bteam){
            sanadaA.emplace_back(Ateam);
            sanadaB.emplace_back(Bteam);
        }
    }

    sort(sanadaA.begin(), sanadaA.end());
    sort(sanadaB.begin(), sanadaB.end());

    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++){
        if(__builtin_popcount(bit) == 0 || __builtin_popcount(bit) == n) continue;

        ll Ateam = 0;
        for(int i=0; i<n; i++){
            if(bit & (1 << i)) Ateam += a[i];
        }

        ll Bteam = asum - Ateam;

        if(Ateam > Bteam){
            int winA = lower_bound(sanadaA.begin(), sanadaA.end(), Ateam) - sanadaA.begin();
            int winB = sanadaB.end() - lower_bound(sanadaB.begin(), sanadaB.end(), Bteam);
            chmax(ans, winA - winB);
        }
    }

    int sz = sanadaA.size();
    printf("%.10f\n", 1. * ans / sz);
}