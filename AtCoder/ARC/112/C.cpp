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

// turn[i] := 頂点 i を選んだ時に、操作が逆転するか
// dp[i] := 頂点 i にいる時に子を選ぶ人が最大化するときのコインの枚数（自分-相手）
vector<int> turn(100010), dp(100010, -1);

void dfs(int cv, vector<vector<int>> &G){
    int t = 1;
    vector<int> change, unchange;
    for(auto nv : G[cv]){
        dfs(nv, G);
        t ^= turn[nv];
        if(turn[nv]) change.emplace_back(dp[nv]);
        else unchange.emplace_back(dp[nv]);
    }
    turn[cv] = t;

    sort(all(change));
    sort(all(unchange));

    while(unchange.size() && unchange.back() > 0){
        dp[cv] += unchange.back(); unchange.pop_back();
    }

    for(int i=change.size()-1; i>=0; i-=2){
        dp[cv] += change[i];
        if(0 <= i - 1) dp[cv] -= change[i - 1];
    }

    if(change.size() % 2){
        dp[cv] -= accumulate(all(unchange), 0);
    }
    else{
        dp[cv] += accumulate(all(unchange), 0);
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> G(n);
    for(int i=1; i<n; i++){
        int p; cin>>p; p--;
        G[p].emplace_back(i);
    }

    dfs(0, G);

    // (自分+相手)-(相手-自分)/2
    cout << (n - dp[0]) / 2 << endl;

    return 0;
}