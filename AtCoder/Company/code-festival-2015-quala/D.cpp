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

int n, m;

bool solve(ll t, vector<int> &x){
    ll l = -1;
    for(int i=0; i<m; i++){
        if(x[i] <= l){
            chmax(l, x[i] + t);
        }
        else{
            if(x[i] - (l + 1) > t) return false;

            // left -> right
            ll r1 = t - x[i] + 2 * (l + 1);
            // right -> left
            ll r2 = (t + x[i] + l + 1) / 2;

            chmax(l, max(r1, r2));
        }
    }

    return n - 1 <= l;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    vector<int> x(m);
    for(int i=0; i<m; i++) cin>>x[i], x[i]--;

    ll ng = -1, ok = INF;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid, x)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}