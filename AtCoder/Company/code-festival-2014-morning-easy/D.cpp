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
    vector<P> xy(n);
    for(int i=0; i<n; i++) cin>>xy[i].first>>xy[i].second;
    vector<int> a(m);
    for(int i=0; i<m; i++) cin>>a[i];

    sort(all(xy));
    sort(all(a));

    vector<int> x(n), y(n);
    for(int i=0; i<n; i++) tie(x[i], y[i]) = xy[i];

    priority_queue<int, vector<int>, greater<int>> que;
    int idx = 0, ans = 0;
    for(int i=0; i<m; i++){
        while(idx < n && x[idx] <= a[i]){
            que.emplace(y[idx]);
            idx++;
        }

        while(que.size()){
            int cy = que.top(); que.pop();
            if(a[i] <= cy){
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}