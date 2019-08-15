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
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int dijkstra(int s, int g, int ticketNum, vector<vector<P>> &G){
    vector<vector<int>> dist(110, vector<int>(15, 1e9));
    priority_queue<T, vector<T>, greater<T>> que;
    dist[s][0] = 0;
    que.push(T(0, s, 0));

    while(!que.empty()){
        int ccost, cv, cticket;
        tie(ccost, cv, cticket) = que.top();
        que.pop();

        if(dist[cv][cticket] < ccost) continue;

        for(auto x : G[cv]){
            int nv = x.first;
            int ncost = x.second;
            if(dist[cv][cticket] + ncost < dist[nv][cticket]){
                dist[nv][cticket] = dist[cv][cticket] + ncost;
                que.push(T(dist[nv][cticket], nv, cticket));
            }
            if(cticket < ticketNum && dist[cv][cticket] + ncost / 2 < dist[nv][cticket+1]){
                dist[nv][cticket+1] = dist[cv][cticket] + ncost / 2;
                que.push(T(dist[nv][cticket+1], nv, cticket+1));
            }
        }
    }

    int ans=1e9;
    for(int i=0; i<=ticketNum; i++){
        chmin(ans, dist[g][i]);
    }

    return ans;
}

int main(){
    while(1){
        int c, n, m, s, d; cin>>c>>n>>m>>s>>d;
        s--, d--;
        if(c == 0) return 0;

        vector<vector<P>> G(110);
        for(int i=0; i<m; i++){
            int a, b, f; cin>>a>>b>>f;
            a--, b--;
            G[a].eb(P(b, f));
            G[b].eb(P(a, f));
        }

        cout << dijkstra(s, d, c, G) << endl;
    }
}