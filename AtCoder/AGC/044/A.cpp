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

    vector<int> base = {2, 3, 5};

    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> cost(4);
        for(int i=0; i<4; i++) cin>>cost[i];

        map<ll, ll> dp;
        dp[n] = 0;

        priority_queue<ll> que;
        que.emplace(n);

        while(que.size()){
            ll cn = que.top(); que.pop();
            ll ccost = dp[cn];

            for(int j=-5; j<=5; j++){
                ll nn = cn + j;
                if(nn <= 0) continue;

                for(int k=0; k<3; k++){
                    if(nn % base[k] == 0){
                        ll divn = nn / base[k];
                        ll ncost = ccost + cost[3] * abs(j);

                        // cost[3] * (nn - divn) がオーバーフローする可能性がある
                        double diff = 1. * cost[k] / cost[3];
                        if(inf < nn - divn || nn - divn > diff){
                            ncost += cost[k];
                        }
                        else{
                            ncost += cost[3] * (nn - divn);
                        }

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
        }

        cout << dp[1] + cost[3] << endl;
    }

    return 0;
}