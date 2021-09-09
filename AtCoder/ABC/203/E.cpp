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

    int n, m; cin >> n >> m;
    map<int, vector<int>> pawn;
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        pawn[x].emplace_back(y);
    }

    set<int> cur;
    cur.emplace(n);
    for(auto i : pawn){
        vector<int> nxt;
        for(auto j : i.second){
            if(cur.count(j - 1) || cur.count(j + 1)){
                nxt.emplace_back(j);
            }
        }

        for(auto j : i.second) cur.erase(j);
        for(auto j : nxt) cur.emplace(j);
    }

    cout << cur.size() << endl;

    return 0;
}