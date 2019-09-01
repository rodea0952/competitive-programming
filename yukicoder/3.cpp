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

    int n; cin>>n;

    vector<int> dist(n+1, inf);
    queue<int> que;
    que.emplace(1);
    dist[1] = 1;

    while(que.size()){
        int cv = que.front(); que.pop();

        int cbit = __builtin_popcount(cv);

        int nv = cv - cbit;
        if(1 <= nv && dist[cv] + 1 < dist[nv]){
            dist[nv] = dist[cv] + 1;
            que.emplace(nv);
        }
        
        nv = cv + cbit;
        if(nv <= n && dist[cv] + 1 < dist[nv]){
            dist[nv] = dist[cv] + 1;
            que.emplace(nv);
        }
    }

    cout << (dist[n] == inf ? -1 : dist[n]) << endl;
}