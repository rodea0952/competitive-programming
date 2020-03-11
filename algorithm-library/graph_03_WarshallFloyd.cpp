vector<vector<int>> dist(1010, vector<int>(1010, inf));
void warshall_floyd(int n){
    for(int i=0; i<n; i++) dist[i][i] = 0;

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}