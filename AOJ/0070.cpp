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

vector<vector<int>> ans(20, vector<int>(1000));
bool used[20];

void solve(int level, int sum){
    if(10 < level) return ;

    for(int i=0; i<=9; i++){
        if(used[i]) continue;
        used[i] = true;
        ans[level+1][sum+(level+1)*i]++;
        solve(level + 1, sum + (level + 1) * i);
        used[i] = false;
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve(0, 0);
    
    int n, s;
    while(cin>>n>>s){
        if(330 < s) s = 0, n = 0;
        cout << ans[n][s] << endl;
    }

    return 0;
}