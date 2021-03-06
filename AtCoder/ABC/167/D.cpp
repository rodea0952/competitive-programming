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
    ll k; cin>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i], a[i]--;

    int logk = 0;
    while((1LL << logk) <= k) logk++;

    vector<vector<int>> doubling(logk, vector<int>(n));
    // doubling[k][i] := 町 i から 2^k 回移動した町
    for(int i=0; i<n; i++) doubling[0][i] = a[i];
    for(int i=0; i+1<logk; i++){
        for(int j=0; j<n; j++){
            doubling[i + 1][j] = doubling[i][doubling[i][j]];
        }
    }

    int cur = 0;
    for(int i=0; i<logk; i++){
        if(k & (1LL << i)) cur = doubling[i][cur];
    }

    cout << cur + 1 << endl;

    return 0;
}