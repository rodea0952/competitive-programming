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

int n, m;

int dijkstra(int s, int g, vector<bool> &city, vector<vector<P>> &G){
    vector<vector<int>> dist(n, vector<int>(m+10, 1e9));
    priority_queue<T, vector<T>, greater<T>> que;
    dist[s][m] = 0;
    que.push(T(0, s, m));

    while(!que.empty()){
        int cdist, cv, crest;
        tie(cdist, cv, crest) = que.top();
        que.pop();

        if(dist[cv][crest] < cdist) continue;

        if(city[cv] && crest < m){
            if(dist[cv][crest] + 1 < dist[cv][crest + 1]){
                dist[cv][crest + 1] = dist[cv][crest] + 1;
                que.push(T(dist[cv][crest + 1], cv, crest + 1));
            }
        }

        for(auto x : G[cv]){
            int nv, ncost;
            tie(nv, ncost) = x;

            if(crest - ncost < 0) continue;

            if(dist[cv][crest] + ncost < dist[nv][crest - ncost]){
                dist[nv][crest - ncost] = dist[cv][crest] + ncost;
                que.push(T(dist[nv][crest - ncost], nv, crest - ncost));
            }
        }
    }

    int ans = 1e9;
    for(int i=0; i<=m; i++){
        ans = min(ans, dist[g][i]);
    }

    return ans;
}

int main(){
    while(1){
        int l, k, a, h; cin>>n>>m>>l>>k>>a>>h;
        if(n == 0) return 0;
        vector<bool> city(n, false);
        for(int i=0; i<l; i++){
            int x; cin>>x;
            city[x] = true;
        }

        vector<vector<P>> G(n);
        for(int i=0; i<k; i++){
            int s, t, x; cin>>s>>t>>x;
            G[s].push_back(P(t, x));
            G[t].push_back(P(s, x));
        }

        int ans = dijkstra(a, h, city, G);

        if(ans == 1e9){
            cout << "Help!" << endl;
        }
        else{
            cout << ans << endl;
        }
    }
}