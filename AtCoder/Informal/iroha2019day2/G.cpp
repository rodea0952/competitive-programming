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

const int MAX_N = 1010;

vector<vector<P>> G(MAX_N);
vector<vector<ll>> dist(MAX_N, vector<ll>(3010, INF));
vector<ll> x(MAX_N), y(MAX_N);
ll n, m, k;

ll dijkstra(int s){
    priority_queue<T, vector<T>, greater<T>> que;
    dist[s][0] = 0;
    que.push(T(0, s, 0));

    while(!que.empty()){
        ll ccost;
        ll cv, cflower;
        tie(ccost, cv, cflower) = que.top();
        //cout << ccost << " " << cv << " " << cflower << endl;
        que.pop();

        if(dist[cv][cflower] < ccost) continue;

        for(auto X : G[cv]){
            ll nv = X.first;
            ll ncost = X.second;

            if(x[cv] == 0){
                if(dist[cv][cflower] + ncost < dist[nv][cflower]){
                    dist[nv][cflower] = dist[cv][cflower] + ncost;
                    que.push(T(dist[nv][cflower], nv, cflower));
                }

                continue;
            }
            for(ll i=0; ; i++){
                if(dist[cv][cflower] + ncost + y[cv] * i < dist[nv][cflower+x[cv]*i]){
                    dist[nv][cflower+x[cv]*i] = dist[cv][cflower] + ncost + y[cv] * i;
                    que.push(T(dist[nv][cflower+x[cv]*i], nv, cflower+x[cv]*i));
                }

                if(2 * k <= cflower + x[cv] * i) break;
            }
        }
    }

    ll ans=INF;
    if(x[n-1] != 0){
        for(ll i=0; i<=k; i++){
            ll rest = (i + (x[n-1] - 1)) / x[n-1] * y[n-1];
            chmin(ans, dist[n-1][k-i] + rest);
        }
    }

    for(int i=k; i<=3005; i++){
        chmin(ans, dist[n-1][i]);
    }

    return (ans == INF ? -1 : ans);
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        G[a].eb(P(b, c));
        G[b].eb(P(a, c));
    }

    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }

    cout << dijkstra(0) << endl;
}