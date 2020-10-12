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

    ll x, y, z; cin>>x>>y>>z;
    vector<char> s(2);
    vector<ll> t(2);
    for(int i=0; i<2; i++) cin>>s[i]>>t[i];

    vector<ll> tb(2);
    for(int i=0; i<2; i++){
        if(s[i] == 'A') tb[i] = x - t[i];
        else if(s[i] == 'B') tb[i] = y - t[i];
        else tb[i] = z - t[i];
    }

    ll ans = INF;
    if(s[0] == s[1]){
        chmin(ans, abs(t[0] - t[1]));
    }
    chmin(ans, t[0] + t[1] - 1);
    chmin(ans, tb[0] + tb[1] + 1);
    chmin(ans, t[0] + tb[1] + min({x, y, z}));
    chmin(ans, t[1] + tb[0] + min({x, y, z}));

    cout << ans << endl;

    return 0;
}