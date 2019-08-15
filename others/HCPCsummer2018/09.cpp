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

const int MAX_N = 100010;

// P(v, cost)
vector<vector<P>> g(MAX_N);
vector<ll> dist(MAX_N, INF);
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        ll pcost = p.first, pv = p.second;
        if(dist[pv] < pcost) continue;

        for(int i=0; i<g[pv].size(); i++){
            P p2 = g[pv][i];
            ll nv = p2.first, ncost = p2.second;
            if(dist[nv] > dist[pv] + ncost){
                dist[nv] = dist[pv] + ncost;
                que.push(P(dist[nv], nv));
            }
        }
    }
}

int main(){
    int v, e, r; cin>>v>>e>>r;
    for(int i=0; i<e; i++){
        int s, t, d; cin>>s>>t>>d;
        g[s].eb(P(t, d));
    }

    dijkstra(r);

    for(int i=0; i<v; i++){
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}