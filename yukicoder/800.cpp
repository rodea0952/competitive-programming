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

    int n, d; cin>>n>>d;

    vector<ll> cnt1(n*n*2+d+10, 0);
    for(int x=1; x<=n; x++){
        for(int y=1; y<=n; y++){
            cnt1[x*x + y*y]++;
        }
    }

    vector<ll> cnt2(n*n*2+d+10, 0);
    for(int z=1; z<=n; z++){
        for(int w=1; w<=n; w++){
            if(w*w - z*z + d < 0) continue;

            cnt2[w*w - z*z + d]++;
        }
    }

    ll ans = 0;
    for(int i=0; i<=n*n*2; i++){
        ans += (cnt1[i] * cnt2[i]);
    }

    cout << ans << endl;
}