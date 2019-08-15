#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> T;

struct UnionFind{
    vector<int> par;
    vector<int> ranks;
    vector<int> size;

private:
    void init(int n = 1){
        par.resize(n);
        ranks.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++){
            par[i] = i;
            ranks[i] = 0;
            size[i] = 1;
        }
    }

public:
    UnionFind(int n = 1){
        init(n);
    }

    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return ;
        if(ranks[x] < ranks[y]) swap(x, y);
        if(ranks[x] == ranks[y]) ranks[x]++;
        par[y] = x;
        size[x] += size[y];
        return ;
    }
};

int main(){
    while(1){
        int n, m; cin>>n>>m;
        if(n == 0) return 0;

        vector<vector<int>> h(1000010);
        int tmax = 0;
        for(int i=0; i<n; i++){
            int H; cin>>H;
            tmax = max(tmax, H);
            h[H].emplace_back(i);
        }

        vector<T> edge;
        for(int i=0; i<m; i++){
            int a, b, c; cin>>a>>b>>c;
            a--, b--;
            edge.emplace_back(c, a, b);
        }
        sort(edge.begin(), edge.end());

        UnionFind uf_con(n);
        for(int i=0; i<m; i++){
            int cost, a, b;
            tie(cost, a, b) = edge[i];
            uf_con.unite(a, b);
        }

        set<int> ufsize;
        for(int i=0; i<n; i++){
            ufsize.emplace(uf_con.find(i));
        }

        if(1 < ufsize.size()){
            cout << 0 << endl;
            continue;
        }

        vector<bool> sinked(n, false);
        int ltime = -1;
        for(int i=1; i<=tmax; i++){
            if(h[i].empty()) continue;

            for(auto cv : h[i]){
                sinked[cv] = true;
            }

            UnionFind uf(n);

            for(int j=0; j<m; j++){
                int cost, a, b;
                tie(cost, a, b) = edge[j];
                if(sinked[a] || sinked[b]) continue;
                
                uf.unite(a, b);
            }

            ufsize.clear();
            for(int i=0; i<n; i++){
                ufsize.emplace(uf.find(i));
            }

            int sz = 1;
            for(int i=0; i<n; i++){
                if(sinked[i]) sz++;
            }

            if(ufsize.size() != sz){
                ltime = i;
                break;
            }
        }

        UnionFind uf(n);
        int ans = 0;
        for(int i=0; i<n; i++){
            sinked[i] = false;
        }

        for(int i=ltime; i<=tmax; i++){
            for(auto cv : h[i]){
                sinked[cv] = true;
            }
        }

        for(int i=0; i<m; i++){
            int cost, a, b;
            tie(cost, a, b) = edge[i];

            if(!sinked[a] || !sinked[b]) continue;
            if(uf.same(a, b)) continue;

            ans += cost;
            uf.unite(a, b);
        }

        for(int i=ltime-1; i>=1; i--){
            if(h[i].empty()) continue;

            for(auto cv : h[i]){
                sinked[cv] = true;
            }

            for(int j=0; j<m; j++){
                int cost, a, b;
                tie(cost, a, b) = edge[j];

                if(!sinked[a] || !sinked[b]) continue;
                if(uf.same(a, b)) continue;

                ans += cost;
                uf.unite(a, b);
            }
        }

        cout << ans << endl;
    }
}