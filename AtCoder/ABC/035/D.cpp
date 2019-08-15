#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;

const int MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

const int MAX_N=100010;

void dijkstra(vector<vector<P>> &G, vector<ll> &dist){
    priority_queue<P, vector<P>, greater<P>> que;
    dist[0]=0;
    que.push(P(0, 0));

    while(!que.empty()){
        P p=que.top(); que.pop();
        ll pcost=p.first, pv=p.second;
        if(dist[pv] < pcost) continue;

        for(int i=0; i<G[pv].size(); i++){
            P p2=G[pv][i];
            ll nv=p2.first, ncost=p2.second;

            if(dist[nv] > dist[pv] + ncost){
                dist[nv] = dist[pv] + ncost;
                que.push(P(dist[nv], nv));
            }
        }
    }
}

int main(){
    ll n, m, t; cin>>n>>m>>t;
    vector<ll> stay(n), a(m), b(m), c(m);
    vector<vector<P>> G1(MAX_N), G2(MAX_N);
    for(int i=0; i<n; i++) cin>>stay[i];
    for(int i=0; i<m; i++){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--, b[i]--;
        G1[a[i]].eb(P(b[i], c[i]));
        G2[b[i]].eb(P(a[i], c[i]));
    }

    vector<ll> dist_from_start(MAX_N, INF);
    vector<ll> dist_to_start(MAX_N, INF);
    dijkstra(G1, dist_from_start);
    dijkstra(G2, dist_to_start);

    ll ans=0;
    for(int i=0; i<n; i++){
        ll rest=t-dist_from_start[i]-dist_to_start[i];
        if(rest<=0) continue;
        chmax(ans, rest*stay[i]);
    }
    cout << ans << endl;
}