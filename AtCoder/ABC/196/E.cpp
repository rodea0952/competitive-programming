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
    vector<ll> a(n), t(n);
    for(int i=0; i<n; i++) cin>>a[i]>>t[i];

    ll lb = -INF, ub = INF, sum = 0;
    for(int i=0; i<n; i++){
        if(t[i] == 1){
            sum += a[i];
            lb += a[i];
            ub += a[i];
        }
        else if(t[i] == 2){
            chmax(lb, a[i]);
            chmax(ub, a[i]);
        }
        else{
            chmin(lb, a[i]);
            chmin(ub, a[i]);
        }
    }

    int q; cin>>q;
    while(q--){
        ll x; cin>>x;
        x += sum;
        if(x < lb) x = lb;
        else if(ub < x) x = ub;
        cout << x << endl;
    }

    return 0;
}