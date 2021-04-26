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

    // 参加者で円を作り、対戦を線で表す
    vector<P> ans;
    if(n % 2){
        for(int i=1; i<=m; i++){
            ans.emplace_back(i, n - i);
        }
    }
    else{
        // 1, ..., n / 2 で差が奇数の線を引く
        int half = n / 2;
        int hl = half / 2, hr = half / 2 + 1;
        for(int i=0; hl-i!=0; i++){
            ans.emplace_back(hl - i, hr + i);
        }
        // n / 2 + 1, ..., n で差が偶数の線を引く
        int tl = half + half / 2, tr = half + half / 2 + 2;
        for(int i=0; tr+i<=n; i++){
            ans.emplace_back(tl - i, tr + i);
        }
    }

    for(int i=0; i<m; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}