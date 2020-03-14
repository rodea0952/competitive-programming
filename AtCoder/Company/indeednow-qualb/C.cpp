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

vector<int> ans;
priority_queue<int, vector<int>, greater<int>> pque;
vector<bool> visited(100010, false);

void dfs(int cv, vector<vector<int>> &G){
    ans.emplace_back(cv);
    visited[cv] = true;

    for(auto nv : G[cv]){
        if(visited[nv]) continue;
        pque.emplace(nv);
    }

    if(pque.empty()) return ;

    int nxt = pque.top(); pque.pop();
    dfs(nxt, G);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    dfs(0, G);

    for(int i=0; i<n; i++){
        cout << ans[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}