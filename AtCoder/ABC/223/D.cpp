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
    vector<int> a(m), b(m);
    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    vector<int> indeg(n, 0);
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        indeg[b[i]]++;
        G[a[i]].emplace_back(b[i]);
    }

    priority_queue<int, vector<int>, greater<int>> que;
    for(int i=0; i<n; i++){
        if(indeg[i] == 0) que.emplace(i);
    }

    vector<int> ans;
    while(que.size()){
        int cv = que.top(); que.pop();
        ans.emplace_back(cv);
        for(auto nv : G[cv]){
            indeg[nv]--;
            if(indeg[nv] == 0) que.emplace(nv);
        }
    }

    if(ans.size() != n){
        cout << -1 << endl;
        return 0;
    }

    for(int i=0; i<n; i++){
        cout << ans[i] + 1 << " \n"[i == n-1];
    }

    return 0;
}