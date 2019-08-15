#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n;

vector<int> dijkstra(int s, vector<vector<P>> &G){
    vector<int> dist(n, 1e9);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(!que.empty()){
        int ccost, cv;
        tie(ccost, cv) = que.top();
        que.pop();

        if(dist[cv] < ccost) continue;

        for(auto x : G[cv]){
            int nv, ncost;
            tie(nv, ncost) = x;

            if(dist[cv] + ncost < dist[nv]){
                dist[nv] = dist[cv] + ncost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return dist;
}

int main(){
    cin>>n;
    vector<vector<P>> G(n);
    for(int i=0; i<n-1; i++){
        int s, t, w; cin>>s>>t>>w;
        G[s].emplace_back(t, w);
        G[t].emplace_back(s, w);
    }

    vector<int> dist1 = dijkstra(0, G);
    int v1 = max_element(dist1.begin(), dist1.end()) - dist1.begin();
    vector<int> dist2 = dijkstra(v1, G);
    int v2 = max_element(dist2.begin(), dist2.end()) - dist2.begin();
    vector<int> dist3 = dijkstra(v2, G);

    for(int i=0; i<n; i++){
        cout << max(dist2[i], dist3[i]) << endl;
    }
}