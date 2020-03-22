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

vector<int> child(100010, 0);
vector<vector<int>> children(100010);

void dfs(int cv, int pv, vector<vector<int>> &G){
    int cnt = 1;
    for(auto nv : G[cv]){
        if(pv == nv) continue;

        dfs(nv, cv, G);
        children[cv].emplace_back(nv);
        cnt += child[nv];
    }
    child[cv] = cnt;
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> G(n);
    for(int i=0; i<n-1; i++){
        int p; cin>>p;
        G[i + 1].emplace_back(p);
        G[p].emplace_back(i + 1);
    }

    dfs(0, -1, G);

    for(int i=0; i<n; i++){
        int ans = 0, sum = 1;
        for(auto j : children[i]){
            chmax(ans, child[j]);
            sum += child[j];
        }
        chmax(ans, n - sum);

        cout << ans << endl;
    }

    return 0;
}