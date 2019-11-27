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

    int m; cin>>m;
    vector<ll> d(m), c(m), num(m);
    ll ans = 0, cur = 0;
    for(int i=0; i<m; i++){
        cin>>d[i]>>c[i];
        ans += (d[i] * c[i]) / 10 + (c[i] - 1);
        
        cur = d[i] * c[i];
        while(1){
            if(0 <= cur && cur <= 9) break;
            int digit1 = cur % 10;
            cur /= 10;
            cur += digit1;
        }

        num[i] = cur;
    }

    ans += (m - 1);
    ll sum = accumulate(num.begin(), num.end(), 0LL);
    ans += sum / 10;

    cout << ans << endl;

    return 0;
}