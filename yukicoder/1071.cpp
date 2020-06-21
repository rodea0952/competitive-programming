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

    ll n, k, x, y; cin>>n>>k>>x>>y;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i] = (a[i] - 1 + k - 1) / k;
    }

    sort(all(a));

    ll ans = 0, pre = 0;
    for(int i=0; i<n; i++){
        if(y <= (n - i) * x){
            // 全員の HP を回復させる方が得をする
            ans += y * (a[i] - pre);
        }
        else{
            // 特定の 1 人を回復させる方が得をする
            ans += (n - i) * x * (a[i] - pre);
        }

        pre = a[i];
    }

    cout << ans << endl;

    return 0;
}