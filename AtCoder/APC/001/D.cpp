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

    int n, m; cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int sz = n - m;
    int need_edge = sz - 1;
    int need_node = 2 * need_edge;

    if(n < need_node){
        cout << "Impossible" << endl;
        return 0;
    }

    if(m == n - 1){
        cout << 0 << endl;
        return 0;
    }

    vector<bool> visited(n, false);
    vector<int> all_score;
    ll ans = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int> score;
            score.emplace_back(a[i]);
            visited[i] = true;
            queue<int> que;
            que.emplace(i);

            while(que.size()){
                int cv = que.front(); que.pop();
                for(auto nv : G[cv]){
                    if(!visited[nv]){
                        score.emplace_back(a[nv]);
                        visited[nv] = true;
                        que.emplace(nv);
                    }
                }
            }

            sort(score.begin(), score.end());
            for(int j=0; j<score.size(); j++){
                if(j == 0) ans += score[j], need_node--;
                else all_score.emplace_back(score[j]);
            }
        }
    }

    sort(all_score.begin(), all_score.end());
    for(int i=0; i<need_node; i++) ans += all_score[i];

    cout << ans << endl;

    return 0;
}