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
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    int ans = inf;
    for(int i=0; i<n; i++){
        priority_queue<P, vector<P>, greater<P>> que;
        for(int j=0; j<n; j++) que.emplace(a[j], 0);

        for(int j=i; j<i+n; j++){
            int level, cnt;
            tie(level, cnt) = que.top(); que.pop();

            level += b[j%n] / 2;
            cnt++;
            que.emplace(level, cnt);
        }

        int sum = 0;
        for(int j=0; j<n; j++){
            int level, cnt;
            tie(level, cnt) = que.top(); que.pop();
            chmax(sum, cnt);
        }

        chmin(ans, sum);
    }

    cout << ans << endl;

    return 0;
}