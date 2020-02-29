class LCA{
public:
    static const int MAX_LOG_V = 30;
    vector<int> parent[MAX_LOG_V]; // 親を2^k回辿って到達する頂点（根を通り過ぎる場合は-1）
    vector<int> depth;

    void init(int V, vector<vector<int>> &G){
        int root = 0;
        for(int i=0; i<MAX_LOG_V; i++) parent[i].resize(V);
        depth.resize(V, -1);

        dfs(root, -1, 0, G);
        
        for(int k=0; k+1<MAX_LOG_V; k++){
            for(int v=0; v<V; v++){
                if(parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    void dfs(int v, int p, int d, vector<vector<int>> &G){
        parent[0][v] = p;
        depth[v] = d;
        for(int i=0; i<G[v].size(); i++){
            if(G[v][i] != p) dfs(G[v][i], v, d+1, G);
        }
    }

    int calc_lca(int u, int v){
        // uとvの深さが同じになるまで親を辿る
        if(depth[u] > depth[v]) swap(u, v);

        for(int k=0; k<MAX_LOG_V; k++){
            if((depth[v] - depth[u]) >> k & 1){
                v = parent[k][v];
            }
        }

        if(u == v) return u;

        for(int k=MAX_LOG_V-1; k>=0; k--){
            if(parent[k][u] != parent[k][v]){
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    int dist(int u, int v){
        return depth[u] + depth[v] - 2 * depth[calc_lca(u, v)];
    }

    bool is_in(int u, int v, int a){
        return (dist(u, a) + dist(a, v) == dist(u, v));
    }
};