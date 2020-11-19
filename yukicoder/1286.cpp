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

    ll d; cin>>d;

    ll ans = INF;
    for(int i=1; i<=64; i++){
        ll ng = 0, ok = INF + 1;
        while(ok - ng > 1){
            ll mid = (ng + ok) / 2;
            ll x = mid, sum = 0;
            for(int j=0; j<i; j++){
                sum += x;
                x /= 2;
            }

            if(d <= sum) ok = mid;
            else ng = mid;
        }

        ll fsum = 0, num = ok;
        for(int j=0; j<i; j++){
            fsum += ok;
            ok /= 2;
        }

        if(fsum == d){
            chmin(ans, num);
        }
    }

    cout << ans << endl;

    return 0;
}