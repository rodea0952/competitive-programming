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

    int n, k; cin>>n>>k;
    vector<int> p(n);
    for(int i=0; i<n; i++) cin>>p[i], p[i]--;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin>>c[i];

    vector<bool> visited(n, false);
    vector<vector<int>> cycle;
    for(int i=0; i<n; i++){
        int cv = i;
        vector<int> cur;
        while(!visited[cv]){
            cur.emplace_back(c[cv]);
            visited[cv] = true;
            cv = p[cv];
        }
        if(!cur.empty()) cycle.emplace_back(cur);
    }

    ll ans = -INF;
    for(int i=0; i<cycle.size(); i++){
        int sz = cycle[i].size();

        vector<ll> sum(2 * sz + 1, 0);
        for(int j=0; j<2*sz; j++){
            sum[j + 1] = sum[j] + cycle[i][j % sz];
        }
        
        vector<ll> magap(sz + 1, -INF);
        for(int j=0; j<2*sz; j++){
            for(int l=j; l<2*sz; l++){
                if(sz < l - j + 1) continue;
                chmax(magap[l - j + 1], sum[l + 1] - sum[j]);
            }
        }

        for(int j=1; j<=sz; j++){
            if(k < j) continue;
            ll cnt = (k - j) / sz;

            chmax(ans, magap[j]);
            if(0 < sum[sz]) chmax(ans, sum[sz] * cnt + magap[j]);
        }
    }

    cout << ans << endl;

    return 0;
}