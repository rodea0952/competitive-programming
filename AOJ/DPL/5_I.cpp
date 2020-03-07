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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// n 個の玉を区別する
// k 個の箱を区別しない
// 入れ方は 1 個以上
// スターリング数
// S(n, k) = S(n - 1, k - 1) + k * S(n - 1, k)
// Σ(-1)^(k - i) * kCi * i^n / (k!) より O(klogn) に減らせる
vector<vector<ll>> S(1010, vector<ll>(1010, 0));
void stir_init(){
    S[0][0] = 1;
    for(int n=1; n<1010; n++){
        for(int k=1; k<1010; k++){
            S[n][k] = S[n - 1][k - 1] + k * S[n - 1][k];
            S[n][k] %= MOD;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin>>n>>k;

    stir_init();

    cout << S[n][k] << endl;

    return 0;
}