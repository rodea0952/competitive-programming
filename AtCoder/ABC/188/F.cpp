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

    ll x, y; cin>>x>>y;

    map<ll, ll> dp;
    dp[y] = 0;
    priority_queue<ll> que;
    que.emplace(y);

    while(que.size()){
        ll cn = que.top(); que.pop();
        ll ccost = dp[cn];

        for(int i=-1; i<=1; i++){
            ll nn = cn + i;
            if(nn <= 0) continue;
            
            if(nn % 2 == 0){
                ll divn = nn / 2;
                ll ncost = ccost + abs(i) + 1;

                if(dp.count(divn)){
                    chmin(dp[divn], ncost);
                }
                else{
                    dp[divn] = ncost;
                    que.emplace(divn);
                }
            }
        }
    }

    ll ans = INF;
    for(auto i : dp){
        chmin(ans, abs(i.first - x) + i.second);
    }

    cout << ans << endl;

    return 0;
}