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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

const int MAX_N = 250010;

vector<vector<P>> G(MAX_N);
vector<ll> dist(MAX_N, INF);
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        ll ccost, cv;
        tie(ccost, cv) = que.top();
        que.pop();

        if(dist[cv] < ccost) continue;

        for(auto x : G[cv]){
            ll nv = x.first;
            ll ncost = x.second;
            if(dist[cv] + ncost < dist[nv]){
                dist[nv] = dist[cv] + ncost;
                que.push(P(dist[nv], nv));
            }
        }
    }
}

int main(){
    int h, w, x; cin>>h>>w>>x;
    int sx, sy, gx, gy; cin>>sy>>sx>>gy>>gx;
    sx--, sy--, gx--, gy--;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>a[i][j];
        }
    }
    vector<ll> c(x);
    for(int i=0; i<x; i++) cin>>c[i];

    vector<vector<int>> toGraph(h, vector<int>(w, 0));
    int cnt=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            toGraph[i][j] = cnt;
            cnt++;
        }
    }

    vector<T> edge;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            for(int k=0; k<4; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];

                if(0 <= ny && ny < h && 0 <= nx && nx < w){
                    if(a[ny][nx] == 0){
                        edge.eb(T(toGraph[i][j], toGraph[ny][nx], 0));
                    }
                    else if(a[i][j] == a[ny][nx]){
                        edge.eb(T(toGraph[i][j], toGraph[ny][nx], 0));
                    }
                    else{
                        edge.eb(T(toGraph[i][j], toGraph[ny][nx], c[a[ny][nx]-1]));
                    }
                }
            }
        }
    }

    for(int i=0; i<edge.size(); i++){
        ll cv, nv, cost;
        tie(cv, nv, cost) = edge[i];
        G[cv].eb(P(nv, cost));
    }

    dijkstra(toGraph[sy][sx]);

    /*
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << toGraph[i][j] << " : " << dist[toGraph[i][j]] << endl;
        }
    }
    */

    cout << dist[toGraph[gy][gx]] << endl;
}