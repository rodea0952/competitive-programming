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

    int n, m; cin>>n>>m;
    vector<ll> h(n), w(m);
    for(int i=0; i<n; i++) cin>>h[i];
    for(int i=0; i<m; i++) cin>>w[i];

    sort(all(h));
    sort(all(w));

    vector<ll> gap0(n / 2, 0);
    for(int i=0; i+1<n; i+=2){
        gap0[i / 2] = h[i + 1] - h[i];
    }
    vector<ll> sum0(n / 2 + 1, 0);
    for(int i=0; i<n/2; i++){
        sum0[i + 1] = sum0[i] + gap0[i];
    }

    vector<ll> gap1(n / 2, 0);
    for(int i=1; i+1<n; i+=2){
        gap1[i / 2] = h[i + 1] - h[i];
    }
    vector<ll> sum1(n / 2 + 1, 0);
    for(int i=0; i<n/2; i++){
        sum1[i + 1] = sum1[i] + gap1[i];
    }

    ll ans = INF;
    for(int i=0; i<m; i++){
        int dist = lower_bound(all(h), w[i]) - h.begin();

        ll cur = 0;
        if(dist % 2 == 0){
            cur += sum0[dist / 2];
            cur += h[dist] - w[i];
            cur += sum1[n / 2] - sum1[dist / 2];
        }
        else{
            cur += sum0[dist / 2];
            cur += w[i] - h[dist - 1];
            cur += sum1[n / 2] - sum1[dist / 2];
        }

        chmin(ans, cur);
    }

    cout << ans << endl;

    return 0;
}