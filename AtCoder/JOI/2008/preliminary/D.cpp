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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m; cin>>m;
    vector<int> ax(m), ay(m);
    for(int i=0; i<m; i++) cin>>ax[i]>>ay[i];
    int n; cin>>n;
    vector<int> bx(n), by(n);
    for(int i=0; i<n; i++) cin>>bx[i]>>by[i];

    set<P> bxy;
    for(int i=0; i<n; i++) bxy.emplace(bx[i], by[i]);

    int ansx, ansy;
    for(int i=0; i<n; i++){
        int cx = bx[i], cy = by[i];
        int cnt = 0;
        for(int j=0; j<m; j++){
            int dx = ax[(j+1)%m] - ax[j];
            int dy = ay[(j+1)%m] - ay[j];

            if(bxy.count(P(cx + dx, cy + dy))){
                cx += dx, cy += dy;
                cnt++;
            }
        }

        if(cnt == m){
            ansx = cx - ax[0];
            ansy = cy - ay[0];
        }
    }

    cout << ansx << " " << ansy << endl;

    return 0;
}