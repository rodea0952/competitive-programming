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

constexpr int MOD = 998244353;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;

    ll ans = 1;
    ll rcnt = 0, gcnt = 0, bcnt = 0;
    ll premin = 1, premid = 1, premax = 1;
    for(int i=0; i<3*n; i++){
        rcnt += (s[i] == 'R');
        gcnt += (s[i] == 'G');
        bcnt += (s[i] == 'B');

        vector<ll> cnt;
        cnt.emplace_back(rcnt);
        cnt.emplace_back(gcnt);
        cnt.emplace_back(bcnt);
        sort(cnt.begin(), cnt.end());

        ll cntmin = cnt[0], cntmid = cnt[1], cntmax = cnt[2];
        
        if(premin < cntmin){
            ans *= (cntmid - cntmin + 1);
            ans %= MOD;
        }

        if(premid < cntmid){
            ans *= (cntmax - cntmid + 1);
            ans %= MOD;
        }

        if(0 < cntmin){
            rcnt--, bcnt--, gcnt--;
            cntmin--, cntmid--, cntmax--;
        }

        premin = cntmin;
        premid = cntmid;
        premax = cntmax;
    }

    for(ll i=1; i<=n; i++){
        ans *= i;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}