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

int solve(int smallsz, int bigsz, int index, vector<vector<int>> &modM){
    int maxmatch = 0, ans = 0;
    for(int i=0; i<bigsz; i++){
        int cnt = 1, cur = modM[index][i];
        while(i + 1 < bigsz && cur == modM[index][i+1]){
            i++;
            cnt++;
        }
        maxmatch += cnt / 2;
    }

    ans += smallsz;
    int rest = bigsz - smallsz;
    ans += min(rest / 2, maxmatch);

    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    vector<vector<int>> modM(m);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        modM[x%m].emplace_back(x);
    }

    for(int i=0; i<m; i++){
        sort(modM[i].begin(), modM[i].end());
    }

    int half = m / 2;
    int ans = modM[0].size() / 2;
    for(int i=1; i<=half; i++){
        int sz1 = modM[i].size(), sz2 = modM[m-i].size();

        if(sz1 == sz2){
            if(i == m - i) ans += sz1 / 2;
            else ans += sz1;
            continue;
        }

        if(sz1 > sz2) ans += solve(sz2, sz1, i, modM);
        else ans += solve(sz1, sz2, m-i, modM);
    }

    cout << ans << endl;

    return 0;
}