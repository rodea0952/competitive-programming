vector<ll> dijkstra(int s, vector<vector<pair<int, ll>>> &G){
    int n = G.size();
    vector<ll> dist(n, INF);
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.emplace(0, s);

    while(que.size()){
        ll ccost; int cv; tie(ccost, cv) = que.top(); que.pop();
        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv; ll ncost; tie(nv, ncost) = nxt;
            
            if(ccost + ncost < dist[nv]){
                dist[nv] = ccost + ncost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return dist;
}

int diameter(vector<vector<pair<ll, int>>> &G){
    vector<ll> dist1 = dijkstra(0, G);
    int v1 = max_element(dist1.begin(), dist1.end()) - dist1.begin();
    vector<ll> dist2 = dijkstra(v1, G);
    return *max_element(dist2.begin(), dist2.end());
}