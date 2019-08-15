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

int dijkstra(int s, int g, vector<vector<P>> &G){
    vector<int> dist(110, 1e9);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        ll ccost = que.top().first;
        ll cv = que.top().second;
        que.pop();
        if(dist[cv] < ccost) continue;

        for(auto x : G[cv]){
            ll nv = x.first;
            ll ncost = x.second;
            if(dist[nv] > dist[cv] + ncost){
                dist[nv] = dist[cv] + ncost;
                que.push(P(dist[nv], nv));
            }
        }
    }

    return (dist[g] == 1e9 ? -1 : dist[g]);
}

int main(){
    while(1){
        int n, k; cin>>n>>k;
        if(n == 0) return 0;

        vector<vector<P>> G(n);
        for(int i=0; i<k; i++){
            int x; cin>>x;
            if(x == 0){
                int a, b; cin>>a>>b;
                a--, b--;
                cout << dijkstra(a, b, G) << endl;
            }
            else{
                int c, d, e; cin>>c>>d>>e;
                c--, d--;
                G[c].eb(P(d, e));
                G[d].eb(P(c, e));
            }
        }
    }
}