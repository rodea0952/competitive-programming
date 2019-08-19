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

    string s, t; cin>>s>>t;
    int n = s.size();
    int m = t.size();

    vector<vector<int>> alp(30);
    for(int i=0; i<n; i++){
        int index = s[i] - 'a';
        alp[index].emplace_back(i); 
    }

    int cur = -1;
    ll ans = 0;
    for(int i=0; i<m; i++){
        int index = t[i] - 'a';

        if(alp[index].size() == 0){
            cout << -1 << endl;
            return 0;
        }

        auto nxt = upper_bound(alp[index].begin(), alp[index].end(), cur);

        if(nxt == alp[index].end()){
            nxt = lower_bound(alp[index].begin(), alp[index].end(), 0);
            ans += (n - 1 - cur) + (*nxt + 1);
        }
        else{
            ans += (*nxt - cur);
        }

        cur = *nxt;
    }

    cout << ans << endl;
}
