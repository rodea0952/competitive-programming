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

vector<bool> visited(100010, false);
deque<int> ans;
bool valid = false;

void dfs(int cv, vector<vector<int>> &G){
    ans.emplace_back(cv);
    visited[cv] = true;
    for(auto nv : G[cv]){
        if(visited[nv]) continue;
        if(valid) continue;

        dfs(nv, G);
    }

    valid = true;
    return ;
}

void rdfs(int cv, vector<vector<int>> &G){
    ans.emplace_front(cv);
    visited[cv] = true;
    for(auto nv : G[cv]){
        if(visited[nv]) continue;
        if(valid) continue;

        rdfs(nv, G);
    }

    valid = true;
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    dfs(0, G);
    ans.pop_front();
    valid = false;
    rdfs(0, G);

    cout << ans.size() << endl;
    for(auto i : ans){
        if(i == ans.back()) cout << i + 1 << endl;
        else cout << i + 1 << " ";
    }

    return 0;
}