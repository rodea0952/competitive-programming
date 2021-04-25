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
    vector<vector<P>> req(n + 1);
    for(int i=0; i<m; i++){
        int x, y, z; cin>>x>>y>>z;
        req[x].emplace_back(y, z);
    }

    auto check = [&](int bit){
        int cnt = __builtin_popcount(bit);
        // 更新するときは x[i] = cnt の条件のみ確認する
        for(auto i : req[cnt]){
            int y, z; tie(y, z) = i;
            for(int j=0; j<y; j++){
                if(bit & (1 << j)) z--;
            }
            if(z < 0) return false;
        }
        return true;
    };

    vector<ll> dp(1 << n, 0);
    dp[0] = 1;
    for(int bit=0; bit<(1<<n); bit++){
        for(int i=0; i<n; i++){
            if(bit & (1 << i)) continue;
            int nbit = bit | (1 << i);
            if(check(nbit)) dp[nbit] += dp[bit];
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}