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
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
    }

    vector<int> ans;
    int sz = inf;
    for(int i=0; i<n; i++){
        vector<int> prev(n, -1), dist(n, inf);
        dist[i] = 0;
        queue<int> que;
        que.emplace(i);
        while(que.size()){
            int cv = que.front(); que.pop();
            for(auto nv : G[cv]){
                if(dist[cv] + 1 < dist[nv]){
                    dist[nv] = dist[cv] + 1;
                    prev[nv] = cv;
                    que.emplace(nv);
                }
            }
        }

        for(int j=0; j<n; j++){
            if(i == j || dist[j] == inf) continue;

            for(auto nv : G[j]){
                if(nv == i){
                    vector<int> tmp;
                    for(int k=j; ; k=prev[k]){
                        tmp.emplace_back(k);
                        if(k == i) break;
                    }

                    if(sz > tmp.size()){
                        ans = tmp;
                        sz = tmp.size();
                    }
                }
            }
        }
    }

    if(sz == inf){
        cout << -1 << endl;
    }
    else{
        cout << sz << endl;
        sort(ans.begin(), ans.end());
        for(auto i : ans){
            cout << i + 1 << endl;
        }
    }

    return 0;
}