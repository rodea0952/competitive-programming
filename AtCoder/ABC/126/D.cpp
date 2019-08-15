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

const int MAX_V = 100010;

vector<vector<P>> G(MAX_V);
vector<ll> dist(MAX_V, INF);
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        int ccost, cv;
        tie(ccost, cv) = que.top();
        que.pop();

        if(dist[cv] < ccost) continue;

        for(auto x : G[cv]){
            int nv = x.first;
            int ncost = x.second;
            if(dist[cv] + ncost < dist[nv]){
                dist[nv] = dist[cv] + ncost;
                que.push(P(dist[nv], nv));
            }
        }
    }
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n-1; i++){
        int u, v, w; cin>>u>>v>>w;
        u--, v--;
        G[u].push_back(P(v, w));
        G[v].push_back(P(u, w));
    }

    dijkstra(0);

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        ans[i] = dist[i] % 2;
        cout << ans[i] << endl;
    }
}