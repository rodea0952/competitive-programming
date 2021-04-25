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
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b; a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    ll ans = 0;
    // 赤で塗る頂点を bit 全探索する
    for(int bit=0; bit<(1<<n); bit++){
        // 赤で塗った時点で条件を満たさない場合はスキップする
        bool valid = true;
        for(int cv=0; cv<n; cv++){
            for(auto nv : G[cv]){
                if((bit & (1 << cv)) && (bit & (1 << nv))) valid = false;
            }
        }
        if(!valid) continue;

        valid = true;
        vector<int> color(n, -1);
        int cnt = 0;
        // 緑 := 0, 青 := 1 として塗っていく
        for(int i=0; i<n; i++){
            if(bit & (1 << i)) continue;
            if(color[i] != -1) continue;
            color[i] = 0;
            queue<int> que;
            que.emplace(i);
            while(que.size()){
                int cv = que.front(); que.pop();
                for(auto nv : G[cv]){
                    if(bit & (1 << nv)) continue;
                    if(color[nv] == color[cv]) valid = false;
                    if(color[nv] == -1){
                        color[nv] = color[cv] ^ 1;
                        que.emplace(nv);
                    }
                }
            }
            cnt++;
        }

        if(valid) ans += (1 << cnt);
    }

    cout << ans << endl;

    return 0;
}