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

ll calcWidth(ll a, ll b){
    return (a + b - 1) / b;
}

bool judge2(ll x, ll y, ll a, ll b){
    ll w = calcWidth(a, y) + calcWidth(b, y);
    return w <= x;
}

bool judge3(ll x, ll y, ll a, ll b, ll c){
    ll w = calcWidth(a, y);
    if(x <= w) return false;
    x -= w;
    return judge2(x, y, b, c) || judge2(y, x, b, c);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;

    vector<ll> perm = {a, b, c};
    sort(all(perm));

    bool valid = false;
    for(int i=0; i<2; i++){
        do{
            if(judge3(x, y, perm[0], perm[1], perm[2])){
                valid = true;
            }
        }while(next_permutation(all(perm)));
        swap(x, y);
    }

    cout << (valid ? "Yes" : "No") << endl;

    return 0;
}