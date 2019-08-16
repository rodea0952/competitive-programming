vector<T> edge;
vector<ll> dist(MAX_V);
int n, m;

void bellman_ford(int s){
    for(int i=0; i<n; i++) dist[i] = INF;
    dist[s] = 0;
    
    while(1){
        bool update = false;
        for(int i=0; i<edge.size(); i++){
            int cv, nv, cost;
            tie(cv, nv, cost) = edge[i];

            if(dist[cv] != INF && dist[nv] > dist[cv] + cost){
                dist[nv] = dist[cv] + cost;
                update = true;
            }
        }

        if(!update) break;
    }
}

bool find_negative_loop(){
    for(int i=0; i<n; i++) dist[i] = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int cv, nv, cost;
            tie(cv, nv, cost) = edge[j];

            if(dist[nv] > dist[cv] + cost){
                dist[nv] = dist[cv] + cost;

                if(i == n - 1) return true;
            }
        }
    }

    return false;
}