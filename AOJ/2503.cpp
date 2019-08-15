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

const int MAX_N = 410;

vector<vector<P>> G(MAX_N);
vector<int> dist(MAX_N, 1e9);
int dijkstra(int s, int g){
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

    return dist[g];
}

int main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        G[a].eb(P(b, -c));
    }

    cout << -dijkstra(0, n-1) << endl;
}