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

    int n; cin>>n;
    vector<ll> x(n), y(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];

    vector<tuple<ll, ll, ll>> dist;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll cur = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            dist.emplace_back(cur, i, j);
        }
    }

    sort(all(dist));

    vector<bool> used(n, false);
    int ans = 0;
    for(auto z:dist){
        ll cdist, i, j;
        tie(cdist, i, j) = z;

        if(used[i] || used[j]) continue;

        if(i == 0){
            used[j] = true;
            ans++;
        }
        else if(j == 0){
            used[i] = true;
            ans++;
        }
        else{
            used[i] = used[j] = true;
        }
    }

    cout << ans << endl;

    return 0;
}