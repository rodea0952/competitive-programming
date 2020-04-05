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

    int n, x, y, z; cin>>n>>x>>y>>z;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    priority_queue<int> que;
    for(int i=0; i<n; i++) que.emplace(a[i] + 1);

    vector<int> yens = {10000, 5000, 1000};
    vector<int> cnts = {z, y, x};

    for(int i=0; i<3; i++){
        int yen = yens[i], cnt = cnts[i];

        // ピッタリ使う
        for(int j=0; j<n; j++){
            int val = que.top(); que.pop();
            int use = min(val / yen, cnt);
            cnt -= use;
            que.emplace(val - use * yen);
        }

        // 残りで値段が高いものから払う
        for(int j=0; j<n; j++){
            int val = que.top(); que.pop();
            if(0 < cnt) cnt--, val = 0;
            que.emplace(val);
        }
    }

    cout << (que.top() > 0 ? "No" : "Yes") << endl;

    return 0;
}