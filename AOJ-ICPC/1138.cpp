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
typedef pair<double, int> P;
typedef tuple<double, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int n, m, p, a, b;

double dijkstra(int s, int g, vector<int> &t, vector<vector<P>> &G){
    vector<vector<double>> dist(35, vector<double>(1000, INF));
    priority_queue<T, vector<T>, greater<T>> que;
    dist[s][0] = 0;
    que.push(T(0, s, 0));

    while(!que.empty()){
        double ccost;
        int cv, cbit;
        tie(ccost, cv, cbit) = que.top();
        que.pop();

        if(dist[cv][cbit] < ccost) continue;

        for(auto x : G[cv]){
            int nv = x.first;
            int ncost = x.second;

            for(int bit=0; bit<(1<<n); bit++){
                if(dist[cv][bit] == INF) continue;

                for(int i=0; i<n; i++){
                    if(!((1<<i) & bit)){
                        int nbit = bit | (1<<i);
                        if(dist[cv][bit] + 1.*ncost / t[i] < dist[nv][nbit]){
                            dist[nv][nbit] = dist[cv][bit] + 1.*ncost / t[i];
                            que.push(T(dist[nv][nbit], nv, nbit));
                        }
                    }
                }
            }
        }
    }

    double ans=INF;
    for(int bit=0; bit<(1<<n); bit++){
        chmin(ans, dist[g][bit]);
    }

    return ans;
}

int main(){
    while(1){
        cin>>n>>m>>p>>a>>b;
        a--, b--;
        if(n == 0) return 0;
        vector<int> t(n);
        for(int i=0; i<n; i++) cin>>t[i];

        vector<vector<P>> G(35);
        for(int i=0; i<p; i++){
            int x, y, z; cin>>x>>y>>z;
            x--, y--;
            G[x].eb(P(y, z));
            G[y].eb(P(x, z));
        }

        double ans = dijkstra(a, b, t, G);

        if(ans == INF){
            cout << "Impossible" << endl;
        }
        else{
            cout << fixed << setprecision(6) << ans << endl;
        }
    }
}