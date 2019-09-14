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

    int n, m, k; cin>>n>>m>>k;
    vector<vector<P>> G(n);
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }

    vector<int> d(k);
    for(int i=0; i<k; i++) cin>>d[i];
    reverse(d.begin(), d.end());

    vector<int> ans;
    for(int i=0; i<n; i++){
        queue<P> que;
        que.emplace(i, 0);
        vector<vector<bool>> visited(n, vector<bool>(k+1, false));
        visited[i][0] = true;

        while(que.size()){
            int cv, cnt;
            tie(cv, cnt) = que.front(); que.pop();

            if(cnt == k){
                ans.emplace_back(i);
                break;
            }

            for(auto nxt : G[cv]){
                int nv, cost;
                tie(nv, cost) = nxt;

                if(cost == d[cnt] && !visited[nv][cnt+1]){
                    visited[nv][cnt+1] = true;
                    que.emplace(nv, cnt + 1);
                }
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }

    return 0;
}