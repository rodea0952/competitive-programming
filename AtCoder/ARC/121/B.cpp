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
    vector<ll> r, g, b;
    for(int i=0; i<2*n; i++){
        ll a; char c; cin>>a>>c;
        if(c == 'R') r.emplace_back(a);
        else if(c == 'G') g.emplace_back(a);
        else b.emplace_back(a);
    }

    if(r.size() % 2 == 0 && g.size() % 2 == 0 && b.size() % 2 == 0){
        cout << 0 << endl;
        return 0;
    }

    sort(all(r));
    sort(all(g));
    sort(all(b));

    ll rgmin = INF;
    for(int i=0; i<r.size(); i++){
        int idx = lower_bound(all(g), r[i]) - g.begin();
        if(0 <= idx && idx < g.size()){
            chmin(rgmin, abs(r[i] - g[idx]));
        }
        idx--;
        if(0 <= idx && idx < g.size()){
            chmin(rgmin, abs(r[i] - g[idx]));
        }
    }

    ll gbmin = INF;
    for(int i=0; i<g.size(); i++){
        int idx = lower_bound(all(b), g[i]) - b.begin();
        if(0 <= idx && idx < b.size()){
            chmin(gbmin, abs(g[i] - b[idx]));
        }
        idx--;
        if(0 <= idx && idx < b.size()){
            chmin(gbmin, abs(g[i] - b[idx]));
        }
    }

    ll brmin = INF;
    for(int i=0; i<b.size(); i++){
        int idx = lower_bound(all(r), b[i]) - r.begin();
        if(0 <= idx && idx < r.size()){
            chmin(brmin, abs(b[i] - r[idx]));
        }
        idx--;
        if(0 <= idx && idx < r.size()){
            chmin(brmin, abs(b[i] - r[idx]));
        }
    }

    ll ans = INF;
    if(r.size() % 2 == 0){
        chmin(ans, min(gbmin, rgmin + brmin));
    }
    else if(g.size() % 2 == 0){
        chmin(ans, min(brmin, rgmin + gbmin));
    }
    else{
        chmin(ans, min(rgmin, gbmin + brmin));
    }

    cout << ans << endl;

    return 0;
}