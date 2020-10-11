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
using P = pair<ll, ll>;
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

    int n; cin>>n;
    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    vector<P> ab(n);
    for(int i=0; i<n; i++){
        ab[i] = P(a[i], b[i]);
    }
    sort(all(ab));

    for(int i=0; i<n; i++){
        a[i] = ab[i].first;
        b[i] = ab[i].second;
    }

    ll sum = 0, bsum = accumulate(all(b), 0LL);
    ll X = 0;
    for(int i=0; i<n; i++){
        sum += b[i];

        if((bsum + 1) / 2 <= sum){
            X = a[i];
            break;
        }
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += b[i] * abs(X - a[i]);
    }

    cout << X << " " << ans << endl;

    return 0;
}