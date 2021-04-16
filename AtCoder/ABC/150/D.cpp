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
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i], a[i] /= 2;

    set<int> div2_cnt;
    for(int i=0; i<n; i++){
        int cur = a[i], cnt = 0;
        while(cur % 2 == 0) cur /= 2, cnt++;
        div2_cnt.emplace(cnt);
    }

    if(div2_cnt.size() != 1){
        cout << 0 << endl;
        return 0;
    }

    ll l = a[0];
    for(int i=1; i<n; i++){
        l = l * a[i] / __gcd(l, a[i]);
        if(m < l){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (m / l + 1) / 2 << endl;

    return 0;
}