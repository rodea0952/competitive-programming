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

vector<vector<int>> G(100000);
vector<bool> c(100000);
bool valid = true;
int cnt;

int dfs(int cv, int pv){
    int cnt = 0;
    for(auto nv : G[cv]){
        if(nv == pv) continue;
        cnt += dfs(nv, cv);
    }

    if(pv != -1 && cnt >= 2) valid = false;
    if(pv == -1 && cnt >= 3) valid = false;

    cnt += c[cv];

    return (1 <= cnt);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    int root;
    for(int i=0; i<m; i++){
        int C; cin>>C;
        C--;
        c[C] = true;
        root = C;
    }

    dfs(root, -1);

    cout << (valid ? "Yes" : "trumpet") << endl;
}