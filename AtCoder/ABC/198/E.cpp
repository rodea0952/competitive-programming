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

vector<int> used(100010);
vector<int> ans;
void dfs(int cv, int pv, vector<int> &c, vector<vector<int>> &G){
    for(auto nv : G[cv]){
        if(nv == pv) continue;
        if(used[c[nv]] == 0) ans.emplace_back(nv);
        used[c[nv]]++;
        dfs(nv, cv, c, G);
        used[c[nv]]--;
    }
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin>>c[i];
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b; a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    ans.emplace_back(0);
    used[c[0]]++;
    dfs(0, -1, c, G);

    sort(all(ans));
    for(auto i : ans) cout << i + 1 << endl;

    return 0;
}