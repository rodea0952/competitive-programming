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

long long decimal_to_integer(string &s, int digit){
    long long base = 1;
    for(int i=0; i<digit; i++) base *= 10;

    if(s.find('.') == string::npos) return stoll(s) * base;

    int point = s.find('.');
    string integer = s.substr(0, point);
    string decimal = s.substr(point + 1);
    while(decimal.size() < digit) decimal += '0';

    return stoll(integer) * base + stoll(decimal);
}

ll integer_sqrt(ll x){
    ll ok = 0, ng = 2 * inf;
    while(ng - ok > 1){
        ll mid = (ng + ok) / 2;
        if(mid * mid <= x) ok = mid;
        else ng = mid;
    }
    return ok;
}

ll floor10000(ll x){
    if(x >= 0) return x / 10000 * 10000;
    else return (x - 9999) / 10000 * 10000;
}

ll ceil10000(ll x){
    if(x >= 0) return (x + 9999) / 10000 * 10000;
    else return x / 10000 * 10000;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string x, y, r; cin>>x>>y>>r;

    ll X = decimal_to_integer(x, 4);
    ll Y = decimal_to_integer(y, 4);
    ll R = decimal_to_integer(r, 4);

    ll lx = ceil10000(X - R);
    ll ux = floor10000(X + R);

    ll ans = 0;
    for(ll i=lx; i<=ux; i+=10000){
        ll s = integer_sqrt(R * R - (X - i) * (X - i));
        ll ly = ceil10000(Y - s);
        ll uy = floor10000(Y + s);
        ans += (uy - ly) / 10000 + 1;
    }

    cout << ans << endl;

    return 0;
}