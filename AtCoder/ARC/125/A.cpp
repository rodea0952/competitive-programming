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

    int n, m; cin >> n >> m;
    vector<int> s(n), t(m);
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<m; i++) cin >> t[i];

    bool s0 = false, s1 = false;
    for(int i=0; i<n; i++){
        if(s[i] == 0) s0 = true;
        else s1 = true;
    }

    bool t0 = false, t1 = false;
    for(int i=0; i<m; i++){
        if(t[i] == 0) t0 = true;
        else t1 = true;
    }

    if((t0 && !s0) || (t1 && !s1)){
        cout << -1 << endl;
        return 0;
    }

    int cost = 0;
    for(int i=1; i<n; i++){
        if(s[0] != s[i] || s[0] != s[n - i]){
            cost = i;
            break;
        }
    }

    int ans = 0;
    bool first = false;

    for(int i=0; i<m; i++){
        ans++;
        if(!first && s[0] != t[i]){
            first = true;
            ans += cost;
        }
        else if(0 < i && t[i - 1] != t[i]){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}