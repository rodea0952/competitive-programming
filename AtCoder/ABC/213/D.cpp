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
void dfs(int cv, int pv, vector<vector<int>> &tree){
    ans.emplace_back(cv);
    for(auto nv : tree[cv]){
        if(nv == pv) continue;
        dfs(nv, cv, tree);
        ans.emplace_back(cv);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> tree(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    for(int i=0; i<n; i++){
        sort(all(tree[i]));
    }

    dfs(0, -1, tree);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }

    return 0;
}