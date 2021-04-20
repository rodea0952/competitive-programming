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
    vector<int> b(m);
    for(int i=0; i<m; i++) cin>>b[i];

    if(m == 1){
        cout << n - 1 << endl;
        return 0;
    }

    double ans = b.back() - b.front();
    double sum = 0;
    // b[i] 以降のワープマスに到達するまで操作 2 を選ぶ
    for(int i=m-1; i>=1; i--){
        sum += b.back() - b[i];
        // m 個のワープマスから b[i] 以降のワープマス（m - i 個）に行く操作回数の期待値
        double warp_expect = 1. * m / (m - i);
        // b[i] 以降のワープマスからの b[m-1] までの総マス数を、b[i] 以降のワープマス数で割る
        // b[i] 以降のワープマスに到達した際の b[m-1] までの操作回数の期待値
        double move_expect = 1. * sum / (m - i);
        chmin(ans, warp_expect + move_expect);
    }

    // b[0] 以前、b[m-1] 以後は操作 1 しか選べない
    ans += (b.front() - 1) + (n - b.back());

    printf("%.10f\n", ans);

    return 0;
}