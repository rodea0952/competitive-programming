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
vector<vector<int>> G(100000);

int s, t;
vector<vector<bool>> visited(100000, vector<bool>(5));

void dijkstra(){
    vector<vector<int>> dist(n, vector<int>(3, 1e9));
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s][0] = 0;
    que.emplace(0, s);

    while(que.size()){
        int ccost, cv;
        tie(ccost, cv) = que.top();
        que.pop();

        if(dist[cv][ccost%3] < ccost) continue;

        for(auto x : G[cv]){
            int nv = x;

            if(dist[cv][(ccost) % 3] + 1 < dist[nv][(ccost + 1) % 3]){
                dist[nv][(ccost + 1) % 3] = dist[cv][(ccost) % 3] + 1;
                que.emplace(dist[nv][(ccost + 1) % 3], nv);
            }

        }
    }

    if(dist[t][0] == 1e9){
        cout << -1 << endl;
    }
    else{
        cout << dist[t][0] / 3 << endl;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        u--, v--;
        G[u].emplace_back(v);
    }

    cin>>s>>t;
    s--, t--;

    dijkstra();
}
