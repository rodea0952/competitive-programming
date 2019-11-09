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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int ans = 0;
    vector<bool> used(n, false);
    for(int i=0; i<n; i++){
        int cur = a[i], cnt = 0;
        while(i < n && cur == a[i]){
            used[i++] = true;
            cnt++;
        }

        if(2 <= cnt) ans += cnt;
        else used[--i] = false;
    }

    for(int i=1; i<n; i++){
        if(used[i]) used[i-1] = true;
    }
    for(int i=n-1; i>=1; i--){
        if(used[i-1]) used[i] = true;
    }

    for(int i=0; i<n; i++){
        int cnt = 0;
        while(i < n && !used[i]){
            i++;
            cnt++;
        }

        ans += (cnt + 1) / 2;
    }

    cout << ans << endl;

    return 0;
}