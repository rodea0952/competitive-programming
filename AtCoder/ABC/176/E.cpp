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

    int h, w, m; cin>>h>>w>>m;
    vector<int> hcnt(h, 0), wcnt(w, 0);
    set<P> point;
    for(int i=0; i<m; i++){
        int r, c; cin>>r>>c;
        r--, c--;
        hcnt[r]++, wcnt[c]++;
        point.emplace(r, c);
    }

    int hmax = *max_element(all(hcnt));
    int wmax = *max_element(all(wcnt));

    vector<int> hidx, widx;
    for(int i=0; i<h; i++){
        if(hcnt[i] == hmax) hidx.emplace_back(i);
    }
    for(int i=0; i<w; i++){
        if(wcnt[i] == wmax) widx.emplace_back(i);
    }

    int ans = hmax + wmax;
    for(auto i : hidx){
        for(auto j : widx){
            if(point.count(P(i, j))) continue;
            cout << ans << endl;
            return 0;
        }
    }

    cout << ans - 1 << endl;

    return 0;
}