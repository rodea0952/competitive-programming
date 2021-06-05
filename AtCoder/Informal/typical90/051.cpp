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

    int n, k; ll p; cin>>n>>k>>p;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<ll> head, tail;
    for(int i=0; i<n/2; i++) head.emplace_back(a[i]);
    for(int i=n/2; i<n; i++) tail.emplace_back(a[i]);

    vector<vector<ll>> price(50);
    for(int bit=0; bit<(1<<tail.size()); bit++){
        ll sum = 0;
        for(int i=0; i<tail.size(); i++){
            if(bit & (1 << i)) sum += tail[i];
        }
        price[__builtin_popcount(bit)].emplace_back(sum);
    }

    for(int i=0; i<50; i++) sort(all(price[i]));

    ll ans = 0;
    for(int bit=0; bit<(1<<head.size()); bit++){
        int rest = k - __builtin_popcount(bit);
        if(rest < 0) continue;
        ll sum = 0;
        for(int i=0; i<head.size(); i++){
            if(bit & (1 << i)) sum += head[i];
        }
        ans += upper_bound(all(price[rest]), p - sum) - price[rest].begin();
    }

    cout << ans << endl;

    return 0;
}