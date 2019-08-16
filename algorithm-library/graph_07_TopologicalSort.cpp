int n;
const int MAX_V = 100010;

vector<vector<int>> G(MAX_V);
bool visited[MAX_V];
int indeg[MAX_V];
list<int> out;

void bfs(int s){
    queue<int> que;
    que.push(s);
    visited[s] = true;

    while(que.size()){
        int cv = que.front(); que.pop();
        out.push_back(cv);
        for(int i=0; i<G[cv].size(); i++){
            int nv = G[cv][i];
            indeg[nv]--;
            if(indeg[nv] == 0 && !visited[nv]){
                visited[nv] = true;
                que.push(nv);
            }
        }
    }
}

void tsort(){
    for(int i=0; i<n; i++){
        for(int j=0; j<G[i].size(); j++){
            int v = G[i][j];
            indeg[v]++;
        }
    }

    for(int i=0; i<n; i++){
        if(indeg[i] == 0 && !visited[i]) bfs(i);
    }

    for(auto i:out){
        cout << i << endl;
    }
}