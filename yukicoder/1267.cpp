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

    int n; cin>>n;
    ll v; cin>>v;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    if(accumulate(all(a), 0LL) <= v){
        cout << "Draw" << endl;
        return 0;
    }

    vector<bool> dp((1 << n), false);
    for(int bit=(1<<n)-1; bit>=0; bit--){
        ll sum = 0;
        for(int i=0; i<n; i++){
            if(bit & (1 << i)) sum += a[i];
        }

        if(v < sum){
            dp[bit] = true;
        }

        for(int i=0; i<n; i++){
            if(bit & (1 << i)) continue;

            if(!dp[bit | (1 << i)] && sum + a[i] <= v){
                dp[bit] = true;
            }
        }
    }

    cout << (dp[0] ? "First" : "Second") << endl;

    return 0;
}