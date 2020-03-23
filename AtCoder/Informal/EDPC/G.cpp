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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<vector<int>> G(n);
    vector<int> indeg(n, 0);
    for(int i=0; i<m; i++){
        int x, y; cin>>x>>y;
        x--, y--;
        G[x].emplace_back(y);
        indeg[y]++;
    }

    queue<int> que;
    for(int i=0; i<n; i++){
        if(indeg[i] == 0) que.emplace(i);
    }

    vector<int> dp(n, 0);
    while(que.size()){
        int cv = que.front(); que.pop();
        for(auto nv : G[cv]){
            indeg[nv]--;
            chmax(dp[nv], dp[cv] + 1);
            if(indeg[nv] == 0) que.emplace(nv);
        }
    }

    cout << *max_element(all(dp)) << endl;

    return 0;
}