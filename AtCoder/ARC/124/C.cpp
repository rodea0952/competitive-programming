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

    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i] >> b[i];

    vector<ll> x;
    for(ll i=1; i*i<=a[0]; i++){
        if(a[0] % i == 0){
            x.emplace_back(i);
            x.emplace_back(a[0] / i);
        }
    }
    sort(all(x));
    x.erase(unique(all(x)), x.end());

    vector<ll> y;
    for(ll i=1; i*i<=b[0]; i++){
        if(b[0] % i == 0){
            y.emplace_back(i);
            y.emplace_back(b[0] / i);
        }
    }
    sort(all(y));
    y.erase(unique(all(y)), y.end());

    ll ans = 0;
    for(auto X : x){
        for(auto Y : y){
            bool valid = true;
            for(int i=0; i<n; i++){
                if(!((a[i] % X == 0 && b[i] % Y == 0) || (a[i] % Y == 0 && b[i] % X == 0))){
                    valid = false;
                }
            }

            if(valid){
                chmax(ans, X * Y / __gcd(X, Y));
            }
        }
    }

    cout << ans << endl;

    return 0;
}