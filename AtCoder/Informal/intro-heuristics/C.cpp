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

    int d; cin>>d;
    vector<int> c(26);
    for(int i=0; i<26; i++) cin>>c[i];
    vector<vector<int>> s(d, vector<int>(26));
    for(int i=0; i<d; i++){
        for(int j=0; j<26; j++) cin>>s[i][j];
    }
    vector<int> t(d);
    vector<set<int>> day(26);
    for(int i=0; i<d; i++){
        cin>>t[i];
        t[i]--;
        day[t[i]].emplace(i);
    }

    for(int i=0; i<26; i++){
        day[i].emplace(-1);
        day[i].emplace(d);
    }

    vector<int> l(26, 0);
    ll ans = 0;
    for(int i=0; i<d; i++){
        ans += s[i][t[i]];
        l[t[i]] = i + 1;
        for(int j=0; j<26; j++){
            ans -= c[j] * (i + 1 - l[j]);
        }
    }

    int m; cin>>m;
    while(m--){
        int dd, ncon; cin>>dd>>ncon;
        dd--, ncon--;
        int pcon = t[dd];
        t[dd] = ncon;

        {
            // 引く
            ans -= s[dd][pcon];
            auto itr = day[pcon].lower_bound(dd);
            int d0 = dd - *prev(itr);
            int d1 = *next(itr) - *prev(itr);
            int d2 = *next(itr) - dd; 
            ans += d0 * (d0 - 1) / 2 * c[pcon];
            ans -= d1 * (d1 - 1) / 2 * c[pcon];
            ans += d2 * (d2 - 1) / 2 * c[pcon];
            day[pcon].erase(dd);
        }

        {
            // 足す
            ans += s[dd][ncon];
            day[ncon].emplace(dd);
            auto itr = day[ncon].lower_bound(dd);
            int d0 = dd - *prev(itr);
            int d1 = *next(itr) - *prev(itr);
            int d2 = *next(itr) - dd;
            ans -= d0 * (d0 - 1) / 2 * c[ncon];
            ans += d1 * (d1 - 1) / 2 * c[ncon];
            ans -= d2 * (d2 - 1) / 2 * c[ncon];
        }

        cout << ans << endl;
    }

    return 0;
}