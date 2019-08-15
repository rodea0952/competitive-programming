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

int n, m, q;
vector<P> dist(100010);
vector<vector<P>> G(100010);

void dijkstra(int s){
    for(int i=0; i<n; i++) dist[i] = P(1e9, 1e9);

    priority_queue<T, vector<T>, greater<T>> que;
    dist[s] = P(0, q);
    que.push(T(0, s, q));

    while(!que.empty()){
        int ccost, cv, cyear;
        tie(ccost, cv, cyear) = que.top();
        que.pop();

        if(ccost == dist[cv].fs){
            if(dist[cv].sc > cyear) continue;
        }

        if(dist[cv].fs < ccost) continue;

        for(auto x : G[cv]){
            int nv, nyear;
            tie(nv, nyear) = x;

            int nnyear = min(nyear, cyear);
            int ncost = ccost + 1;

            if(ncost == dist[nv].fs){
                if(dist[nv].sc < nnyear){
                    dist[nv] = P(ncost, nnyear);
                    que.push(T(dist[nv].fs, nv, nnyear));
                }
            }
            else if(ncost < dist[nv].fs){
                dist[nv] = P(ncost, nnyear);
                que.push(T(dist[nv].fs, nv, nnyear));
            }
        }
    }
}

int main(){
    cin>>n>>m>>q;
    vector<int> u(m), v(m);
    for(int i=0; i<m; i++){
        cin>>u[i]>>v[i];
        u[i]--, v[i]--;
    }

    vector<int> changeYear(m, q);
    for(int i=0; i<q; i++){
        int r; cin>>r;
        r--;
        changeYear[r] = i;
    }

    for(int i=0; i<m; i++){
        G[u[i]].eb(P(v[i], changeYear[i]));
        G[v[i]].eb(P(u[i], changeYear[i]));
    }

    dijkstra(0);

    vector<int> cnt(q+1);
    for(int i=0; i<n; i++){
        cnt[dist[i].sc]++;
    }

    for(int i=0; i<q; i++){
        if(0 < i) cnt[i] += cnt[i-1];
        cout << cnt[i] << endl;
    }
}