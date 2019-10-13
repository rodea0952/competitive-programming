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

    ll n, a, b; cin>>n>>a>>b;

    if(!(a + b - 1 <= n && n <= a * b)){
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans(n);
    for(int i=0; i<b; i++){
        ans[i] = b - i;
    }

    if(a == 1){
        for(int i=0; i<n; i++){
            cout << ans[i] << " \n"[i == n-1];
        }
        return 0;
    }

    int index = b;

    int cnt = (n - b) / (a - 1);
    int rem = (n - b) % (a - 1);

    int pre = b;
    for(int i=index; i<n;){
        int curcnt = cnt + (rem-- > 0);
        int num = pre + curcnt;
        int cur = num;

        for(int j=i; j<i+curcnt; j++){
            ans[j] = num--;
        }

        i += curcnt;
        pre = cur;
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }

    return 0;
}