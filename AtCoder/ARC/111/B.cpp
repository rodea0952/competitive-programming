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

    int n; cin>>n;
    vector<vector<int>> G(400000);
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b; a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    int ans = 0;
    vector<bool> visited(400000, false);
    for(int i=0; i<400000; i++){
        if(visited[i]) continue;
        visited[i] = true;
        int sum = 0;
        bool is_tree = true;
        queue<P> que;
        que.emplace(i, -1);
        while(que.size()){
            int cv, pv; tie(cv, pv) = que.front(); que.pop();
            sum++;
            for(auto nv : G[cv]){
                if(nv == pv) continue;
                if(visited[nv]){
                    is_tree = false;
                    continue;
                }
                visited[nv] = true;
                que.emplace(nv, cv);
            }
        }

        ans += sum - is_tree;
    }

    cout << ans << endl;

    return 0;
}