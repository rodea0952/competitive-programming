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
#define chmin(a, b) ((a) = min((a), (b)))
#define chmax(a, b) ((a) = max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;

int dijkstra(vector<vector<P>> &G){
    vector<vector<int>> dist(n, vector<int>(2, 1e9));
    priority_queue<T, vector<T>, greater<T>> que;
    dist[0][0] = 0;
    que.emplace(0, 0, 0);

    while(!que.empty()){
        int ccost, cv, cused;
        tie(ccost, cv, cused) = que.top();
        que.pop();

        if(dist[cv][cused] < ccost) continue;

        for(auto x : G[cv]){
            int nv, ncost;
            tie(nv, ncost) = x;
            
            if(dist[cv][cused] + ncost < dist[nv][cused]){
                dist[nv][cused] = dist[cv][cused] + ncost;
                que.emplace(dist[nv][cused], nv, cused);
            }

            if(cused) continue;

            for(auto y : G[nv]){
                int nnv, nncost;
                tie(nnv, nncost) = y;

                if(dist[cv][0] < dist[nnv][1]){
                    dist[nnv][1] = dist[cv][0];
                    que.emplace(dist[nnv][1], nnv, 1);
                }
            }
        }
    }

    return min(dist[n-1][0], dist[n-1][1]);
}

int main(){
    while(1){
        cin>>n>>m;
        if(n == 0) return 0;

        vector<vector<P>> G(n);
        for(int i=0; i<m; i++){
            int a, b, c; cin>>a>>b>>c;
            a--, b--;
            G[a].emplace_back(b, c);
            G[b].emplace_back(a, c);
        }

        cout << dijkstra(G) << endl;
    }
}