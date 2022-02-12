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

    int m; cin >> m;
    vector<vector<int>> G(9);
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v; u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> p(8);
    for(int i=0; i<8; i++) cin >> p[i], p[i]--;

    string base = "---------";
    for(int i=0; i<8; i++){
        base[p[i]] = i + '0';
    }

    queue<string> que;
    que.emplace(base);
    map<string, int> memo;
    memo[base] = 0;

    while(que.size()){
        string cur = que.front(); que.pop();
        int ev = -1;
        for(int i=0; i<9; i++){
            if(cur[i] == '-') ev = i;
        }

        for(auto nv : G[ev]){
            string s = cur;
            swap(s[ev], s[nv]);
            if(memo.count(s)) continue;
            memo[s] = memo[cur] + 1;
            que.emplace(s);
        }
    }

    cout << (memo.count("01234567-") == 0 ? -1 : memo["01234567-"]) << endl;

    return 0;
}