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

int dijkstra(vector<vector<T>> &G){
    vector<int> dist(n, 1e9);
    priority_queue<T, vector<T>, greater<T>> que;
    que.emplace(0, 0, 0);

    int ans = 0;
    while(!que.empty()){
        int cdist, cv, ccost;
        tie(cdist, cv, ccost) = que.top();
        que.pop();
        
        if(dist[cv] <= cdist) continue;
        dist[cv] = cdist;
        ans += ccost;

        for(auto x : G[cv]){
            int nv, ndist, ncost;
            tie(nv, ndist, ncost) = x;
            if(dist[nv] != 1e9) continue;
            que.emplace(dist[cv] + ndist, nv, ncost);
        }
    }

    return ans;
}

int main(){
    while(1){
        cin>>n>>m;
        if(n == 0) return 0;
        vector<vector<T>> G(n);
        for(int i=0; i<m; i++){
            int u, v, d, c; cin>>u>>v>>d>>c;
            u--, v--;
            G[u].emplace_back(v, d, c);
            G[v].emplace_back(u, d, c);
        }

        cout << dijkstra(G) << endl;
    }
}