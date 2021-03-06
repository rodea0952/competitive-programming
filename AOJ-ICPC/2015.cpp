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

    while(1){
        int n, m; cin>>n>>m;
        if(n == 0) break;

        vector<int> hsum(n+1, 0), wsum(m+1, 0);
        for(int i=0; i<n; i++){
            int h; cin>>h;
            hsum[i+1] = hsum[i] + h;
        }
        for(int i=0; i<m; i++){
            int w; cin>>w;
            wsum[i+1] = wsum[i] + w;
        }

        map<int, int> hcnt;
        for(int i=0; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                hcnt[hsum[j] - hsum[i]]++;
            }
        }

        int ans = 0;
        for(int i=0; i<=m; i++){
            for(int j=i+1; j<=m; j++){
                ans += hcnt[wsum[j] - wsum[i]];
            }
        }

        cout << ans << endl;
    }

    return 0;
}