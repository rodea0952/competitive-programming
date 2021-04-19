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

vector<int> f(400010), g(400010);

void init(){
    for(int i=1; i<=400000; i++){
        int cur = i;
        while(cur % 3 == 0) cur /= 3, f[i]++;
        g[i] = cur % 3;
    }
    g[0] = 1;
    for(int i=1; i<=400000; i++){
        f[i] += f[i - 1];
        g[i] = g[i] * g[i - 1] % 3;
    }
    return ;
}

// g[n] < g[r] * g[n - r] の際の求め方がよくわからない
int nCr_mod3(int n, int r){
    if(f[n] > f[r] + f[n - r]) return 0;
    if(g[n] == 1 && g[r] * g[n - r] % 3 == 1) return 1;
    if(g[n] == 1 && g[r] * g[n - r] % 3 == 2) return 2;
    if(g[n] == 2 && g[r] * g[n - r] % 3 == 1) return 2;
    if(g[n] == 2 && g[r] * g[n - r] % 3 == 2) return 1;
    return -1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; string s; cin>>n>>s;

    init();

    int ret = 0;
    for(int i=0; i<n; i++){
        int num = -1;
        if(s[i] == 'B') num = 0;
        if(s[i] == 'W') num = 1;
        if(s[i] == 'R') num = 2;
        ret += num * nCr_mod3(n - 1, i);
        ret %= 3;
    }

    if(n % 2 == 0) ret = (3 - ret) % 3;

    string ans;
    if(ret == 0) ans = "B";
    if(ret == 1) ans = "W";
    if(ret == 2) ans = "R";

    cout << ans << endl;

    return 0;
}