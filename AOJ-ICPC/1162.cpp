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
typedef tuple<double, int, int, int> T2;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

double dijkstra(int s, int g, vector<vector<T>> &G){
    vector<vector<vector<double>>> dist(40, vector<vector<double>>(40, vector<double>(40, INF)));
    priority_queue<T2, vector<T2>, greater<T2>> que;
    dist[s][35][0] = 0;
    que.push(T2(0, s, 35, 0));

    while(!que.empty()){
        double cdist;
        int cv, pv, pvel;
        tie(cdist, cv, pv, pvel) = que.top();
        que.pop();
        
        for(auto x : G[cv]){
            int nv, ndist, nlim;
            tie(nv, ndist, nlim) = x;

            if(nv == pv) continue;

            for(int i=-1; i<=1; i++){
                int nvel = pvel + i;
                if(nvel <= 0) continue;
                if(nlim < nvel) continue;
                
                if(dist[cv][pv][pvel] + 1. * ndist / nvel < dist[nv][cv][nvel]){
                    dist[nv][cv][nvel] = dist[cv][pv][pvel] + 1. * ndist / nvel;
                    que.push(T2(dist[nv][cv][nvel], nv, cv, nvel));
                }
            }
        }
    }

    double ans = INF;
    for(int i=0; i<=30; i++){
        ans = min(ans, dist[g][i][1]);
    }

    return ans;
}

int main(){
    while(1){
        int n, m; cin>>n>>m;
        if(n == 0) return 0;
        int s, g; cin>>s>>g;
        s--, g--;
        vector<vector<T>> G(n);
        for(int i=0; i<m; i++){
            int x, y, d, c; cin>>x>>y>>d>>c;
            x--, y--;
            G[x].push_back(T(y, d, c));
            G[y].push_back(T(x, d, c));
        }

        double ans = dijkstra(s, g, G);
        if(ans == INF){
            cout << "unreachable" << endl;
        }
        else{
            cout << fixed << setprecision(8) << ans << endl;
        }
    }
}