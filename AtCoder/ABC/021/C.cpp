#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

vector<vector<P>> G(110);
int n;

int dijkstra(int s, int g){
    vector<int> dist(n, MOD);
    vector<int> ans(n);
    queue<P> que;
    dist[s]=0, ans[s]=1;
    que.push(P(s, 0));

    while(!que.empty()){
        P p=que.front(); que.pop();
        int pri_v=p.first, cost=p.second;

        for(int i=0; i<G[pri_v].size(); i++){
            int next_v=G[pri_v][i].first;
            if(dist[next_v] > cost + 1){
                ans[next_v] = ans[pri_v];
                dist[next_v] = cost + 1;
                que.push(P(next_v, dist[next_v]));
            }
            else if(cost + 1 == dist[next_v]){
                ans[next_v] = (ans[next_v] + ans[pri_v]) % MOD;
            }
        }
    }
    return ans[g];
}

int main() {
    int a, b, m; cin>>n>>a>>b>>m;
    a--, b--;
    for(int i=0; i<m; i++) {
        int x, y; cin>>x>>y;
        x--, y--;
        G[x].push_back(P(y, 1));
        G[y].push_back(P(x, 1));
    }
    cout << dijkstra(a, b) << endl;
}