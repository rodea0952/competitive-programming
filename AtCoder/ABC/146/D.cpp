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

vector<int> ans(100010);
int k = 0;

void dfs(int cv, int pv, int pnum, vector<vector<P>> &G){
    int cnt = 0;
    for(auto nxt : G[cv]){
        int nv, index;
        tie(nv, index) = nxt;

        if(nv == pv) continue;

        ans[index] = (pnum + 1 + cnt) % k;
        dfs(nv, cv, (pnum + 1 + cnt) % k, G);
        cnt++;
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<P>> G(n);
    vector<int> cnt(n, 0);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        cnt[a]++;
        cnt[b]++;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }

    for(int i=0; i<n; i++){
        chmax(k, cnt[i]);
    }

    dfs(0, -1, -1, G);

    cout << k << endl;
    for(int i=0; i<n-1; i++) cout << ans[i] + 1 << endl;

    return 0;
}
