template <typename flow_t, typename cost_t>
struct PrimalDual{
    const cost_t INF;

    struct edge{
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
        bool is_rev;
    };

    vector<vector<edge>> G;
    vector<cost_t> potential, min_cost; // potential[v]:= s-v間の最短距離
    vector<int> prevv, preve;           // 直前の頂点と辺 

    PrimalDual(int V) : G(V), INF(numeric_limits<cost_t>::max()) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost){
        G[from].emplace_back((edge){to, cap, cost, (int)G[to].size(), false});
        G[to].emplace_back((edge){from, 0, -cost, (int)G[from].size()-1, true});
    }

    // s から t への流量 f の最小費用流を求める
    // 流せない場合は -1 を返す
    cost_t min_cost_flow(int s, int t, flow_t f){
        int V = G.size();
        cost_t ret = 0;
        using Pci = pair<cost_t, int>;
        priority_queue<Pci, vector<Pci>, greater<Pci>> que;
        potential.assign(V, 0);
        prevv.assign(V, -1);
        preve.assign(V, -1);

        while(0 < f){
            min_cost.assign(V, INF);
            que.emplace(0, s);
            min_cost[s] = 0;
            while(que.size()){
                cost_t ccost; int cv; tie(ccost, cv) = que.top(); que.pop();
                if(min_cost[cv] < ccost) continue;
                for(int i=0; i<G[cv].size(); i++){
                    edge &e = G[cv][i];
                    cost_t ncost = min_cost[cv] + e.cost + potential[cv] - potential[e.to];
                    if(0 < e.cap && ncost < min_cost[e.to]){
                        min_cost[e.to] = ncost;
                        prevv[e.to] = cv, preve[e.to] = i;
                        que.emplace(min_cost[e.to], e.to);
                    }
                }
            }

            // これ以上流せない
            if(min_cost[t] == INF) return -1;
            
            for(int v=0; v<V; v++) potential[v] += min_cost[v];
            
            // s-t 間最短路に沿って目一杯流す
            flow_t addflow = f;
            for(int v=t; v!=s; v=prevv[v]){
                addflow = min(addflow, G[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for(int v=t; v!=s; v=prevv[v]){
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= addflow;
                G[v][e.rev].cap += addflow;
            }
        }

        return ret;
    }

    void output(){
        for(int i=0; i<G.size(); i++){
            for(auto &e:G[i]){
                if(e.is_rev) continue;
                auto &rev_e = G[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl; 
            }
        }
    }
};