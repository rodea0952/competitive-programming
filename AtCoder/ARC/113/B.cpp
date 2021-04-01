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

ll modpow(ll a, ll b, int m){
    if(b == 0) return 1;
    else if(b % 2 == 0){
        ll d = modpow(a, b / 2, m) % m;
        return d * d;
    }
    else{
        return a * modpow(a, b - 1, m) % m;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a, b, c; cin>>a>>b>>c;

    a %= 10;
    vector<int> v;
    int cur = a;
    while(count(all(v), cur) == 0){
        v.emplace_back(cur);
        cur *= a;
        cur %= 10;
    }

    int m = v.size();

    cout << v[(modpow(b, c, m) + m - 1) % m] << endl;

    return 0;
}