vector<vector<P>> G(MAX_V);
vector<ll> dist(MAX_V, INF);
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(que.size()){
        int ccost, cv;
        tie(ccost, cv) = que.top(); que.pop();

        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv, ncost;
            tie(nv, ncost) = nxt;
            
            if(dist[cv] + ncost < dist[nv]){
                dist[nv] = dist[cv] + ncost;
                que.emplace(dist[nv], nv);
            }
        }
    }
}