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

vector<ll> children_cnt(1000010);
ll ans = 0;

void dfs1(int cv, vector<vector<int>> &G){
    int cnt = 1;
    for(auto nv : G[cv]){
        dfs1(nv, G);
        cnt += children_cnt[nv];
    }
    children_cnt[cv] = cnt;
    return ;
}

void dfs2(int cv, int passed_cnt, vector<vector<int>> &G){
    ans += (children_cnt[cv] - 1) * passed_cnt;
    ans %= MOD;
    passed_cnt++;
    for(auto nv : G[cv]){
        dfs2(nv, passed_cnt, G);
    }
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> G(n);
    set<int> num;
    for(int i=0; i<n; i++) num.emplace(i);

    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        num.erase(b);
    }

    int root = *num.begin();

    dfs1(root, G);

    dfs2(root, 1, G);

    cout << ans << endl;

    return 0;
}