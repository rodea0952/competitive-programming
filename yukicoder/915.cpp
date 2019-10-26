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

    int q; cin>>q;
    while(q--){
        ll a, b, c; cin>>a>>b>>c;
        if(c == 1) cout << -1 << endl;
        else{
            ll ans = INF;
            ll cnt = 0;
            while(a > 0){
                int greedy = (a + (c - 1) - 1) / (c - 1);
                chmin(ans, (cnt + greedy) * b);
                
                if(a % c != 0) cnt++;
                a /= c;
                if(a != 0) cnt++;
            }
            chmin(ans, cnt * b);

            cout << ans << endl;
        }
    }

    return 0;
}