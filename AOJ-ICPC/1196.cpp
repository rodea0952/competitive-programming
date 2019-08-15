#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n;

vector<bool> visited(810);
vector<bool> isChild(810);
int childSum;

void dfsChild(int cv, vector<vector<P>> &G){
    visited[cv] = true;

    bool haveChild = false;
    for(auto x : G[cv]){
        int nv, ncost;
        tie(nv, ncost) = x;
        if(!visited[nv]){
            haveChild = true;
            dfsChild(nv, G);
        }
    }

    if(!haveChild){
        isChild[cv] = true;
        childSum += get<1>(G[cv][0]);
    }
}

vector<int> dijkstra(int s, vector<vector<P>> &G){
    vector<int> dist(n, 1e9);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);

    while(que.size()){
        int ccost, cv;
        tie(ccost, cv) = que.top();
        que.pop();

        if(dist[cv] < ccost) continue;

        for(auto x : G[cv]){
            int nv, ncost;
            tie(nv, ncost) = x;

            if(isChild[nv]) continue;
            
            if(dist[cv] + ncost < dist[nv]){
                dist[nv] = dist[cv] + ncost;
                que.emplace(dist[nv], nv);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(dist[i] == 1e9){
            dist[i] = -1;
        }
    }

    return dist;
}

signed main(){
    while(1){
        childSum = 0;
        for(int i=0; i<810; i++){
            visited[i] = false;
            isChild[i] = false;
        }

        cin>>n;
        if(n == 0) return 0;
        
        vector<int> p(n-1);
        for(int i=0; i<n-1; i++){
            cin>>p[i];
            p[i]--;
        }

        int sum = 0;
        vector<int> d(n-1);
        for(int i=0; i<n-1; i++){
            cin>>d[i];
            sum += d[i];
        }

        vector<vector<P>> G(n);
        for(int i=0; i<n-1; i++){
            G[i+1].emplace_back(p[i], d[i]);
            G[p[i]].emplace_back(i+1, d[i]);
        }

        int root = -1;
        for(int i=0; i<n; i++){
            if(1 < G[i].size()){
                root = i;
                break;
            }
        }

        dfsChild(root, G);

        vector<int> dist1 = dijkstra(root, G);
        int v1 = max_element(dist1.begin(), dist1.end()) - dist1.begin();
        vector<int> dist2 = dijkstra(v1, G);
        int diameter = *max_element(dist2.begin(), dist2.end());

        int rest = sum - (diameter + childSum);

        cout << childSum + diameter * 2 + rest * 3 << endl;
    }
}