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

    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();

    int dot_cnt = count(all(s), '.');
    if(dot_cnt <= k){
        cout << n << endl;
        return 0;
    }

    vector<int> dot_idx = {-1, n};
    for(int i=0; i<n; i++){
        if(s[i] == '.') dot_idx.emplace_back(i);
    }
    sort(all(dot_idx));

    int ans = 0;
    for(int i=1; i+k<dot_idx.size(); i++){
        int l = dot_idx[i-1] + 1;
        int r = dot_idx[i+k] - 1;
        chmax(ans, r - l + 1);
    }

    cout << ans << endl;

    return 0;
}