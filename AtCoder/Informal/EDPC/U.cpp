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
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>a[i][j];
    }

    vector<ll> score((1<<n), 0);
    for(int bit=0; bit<(1<<n); bit++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((bit & (1 << i)) && (bit & (1 << j))){
                    score[bit] += a[i][j];
                }
            }
        }
        score[bit] /= 2;
    }

    vector<ll> dp((1<<n), 0);
    for(int bit=0; bit<(1<<n); bit++){
        int unused = bit ^ ((1 << n) - 1);
        for(int cur=unused; cur>0; cur=(cur-1)&unused){
            chmax(dp[bit | cur], dp[bit] + score[cur]);
        }
    }

    cout << dp[(1<<n)-1] << endl;

    return 0;
}