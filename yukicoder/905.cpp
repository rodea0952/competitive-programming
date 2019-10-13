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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<P> plus, minus;
    for(int i=0; i<n; i++){
        int spos = i;
        ll cur = a[i];
        while(i + 1 < n && cur <= a[i+1]){
            cur = a[++i];
        }
        int epos = i;
        plus.emplace_back(epos, spos);
    }

    for(int i=0; i<n; i++){
        int spos = i;
        ll cur = a[i];
        while(i + 1 < n && cur >= a[i+1]){
            cur = a[++i];
        }
        int epos = i;
        minus.emplace_back(epos, spos);
    }

    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        int f = 0, g = 0;
        auto itr = lower_bound(plus.begin(), plus.end(), P(r, -1));
        if((*itr).second <= l) f = 1;
        itr = lower_bound(minus.begin(), minus.end(), P(r, -1));
        if((*itr).second <= l) g = 1;

        cout << f << " " << g << endl;
    }

    return 0;
}