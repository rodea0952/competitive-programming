vector<long long> dijkstra(int s, vector<vector<pair<int, long long>>> &G){
    int n = G.size();
    vector<long long> dist(n, 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
    que.emplace(0, s);

    while(que.size()){
        long long ccost;
        int cv; 
        tie(ccost, cv) = que.top(); que.pop();
        if(dist[cv] < ccost) continue;

        for(auto nxt : G[cv]){
            int nv;
            long long ncost;
            tie(nv, ncost) = nxt;
            
            if(ccost + ncost < dist[nv]){
                dist[nv] = ccost + ncost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    return dist;
}