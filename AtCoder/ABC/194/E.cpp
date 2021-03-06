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
    vector<vector<int>> G(n + 1);
    for(int i=0; i<=n; i++) G[i].emplace_back(-1);
    for(int i=0; i<n; i++){
        int a; cin>>a;
        G[a].emplace_back(i);
    }
    for(int i=0; i<=n; i++) G[i].emplace_back(n);

    for(int i=0; i<=n; i++){
        for(int j=0; j+1<G[i].size(); j++){
            int pre = G[i][j], cur = G[i][j+1];
            if(cur - pre - 1 >= m){
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}