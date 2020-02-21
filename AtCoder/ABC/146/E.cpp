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

    int n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    if(k == 1){
        cout << 0 << endl;
        return 0;
    }

    vector<ll> sum(n+1, 0);
    for(int i=0; i<n; i++) sum[i+1] = sum[i] + a[i];

    map<int, int> cnt;
    cnt[0] = 1;

    ll ans = 0;
    for(int r=1; r<=n; r++){
        int x = (sum[r] - r) % k;
        ans += cnt[x];
        cnt[x]++;

        // 要素の数が k 以上になった場合、左から消していく
        int l = r - k + 1;
        if(0 <= l){
            int y = (sum[l] - l) % k;
            cnt[y]--;
        }
    }

    cout << ans << endl;

    return 0;
}
