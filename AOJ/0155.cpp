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
typedef pair<int, double> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

void dijkstra(int s, int g, vector<vector<P>> &G){
    vector<int> pv(110, 0);
    vector<double> dist(110, 1e9);
    pv[s] = -1;
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
                pv[nv] = cv;
                que.push(P(dist[nv], nv));
            }
        }
    }

    if(dist[g] == 1e9){
        cout << "NA" << endl;
    }
    else{
        vector<int> ans;
        for(int i=g; i!=-1; i=pv[i]){
            ans.eb(i+1);
        }

        for(int i=ans.size()-1; i>=0; i--){
            cout << ans[i] << " \n"[i == 0];
        }
    }
}

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;

        vector<int> b(n), x(n), y(n);
        for(int i=0; i<n; i++){
            cin>>b[i]>>x[i]>>y[i];
            b[i]--;
        }

        vector<vector<P>> G(110);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double cost = sqrt(abs(y[i] - y[j]) * abs(y[i] - y[j]) + abs(x[i] - x[j]) * abs(x[i] - x[j]));

                if(50.0 < cost) continue;

                G[b[i]].eb(P(b[j], cost));
                G[b[j]].eb(P(b[i], cost));
            }
        }

        int m; cin>>m;
        while(m--){
            int s, g; cin>>s>>g;
            s--, g--;
            dijkstra(s, g, G);
        }
    }
}