#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 100010;

vector<vector<int>> G(MAX_V);
vector<pair<int, int>> bridge;
vector<int> articulation;
int ord[MAX_V], low[MAX_V];
bool visited[MAX_V];

void dfs(int cv, int pv, int &k){
    visited[cv] = true;

    ord[cv] = k++;
    low[cv] = ord[cv];

    bool isArticulation = false;
    int cnt = 0;

    for(int i=0; i<G[cv].size(); i++){
        int nv = G[cv][i];

        if(!visited[nv]){
            cnt++;
            dfs(nv, cv, k);
            low[cv] = min(low[cv], low[nv]);
            if(~pv && ord[cv] <= low[nv]) isArticulation = true;
            if(ord[cv] < low[nv]) bridge.emplace_back(minmax(cv, nv));
        }
        else if(nv != pv){
            low[cv] = min(low[cv], ord[nv]);
        }
    }

    if(pv == -1 && 1 < cnt) isArticulation = true;
    if(isArticulation) articulation.emplace_back(cv);
}

int main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int s, t; cin>>s>>t;
        G[s].emplace_back(t);
        G[t].emplace_back(s);
    }

    int k = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]) dfs(i, -1, k);
    }

    sort(articulation.begin(), articulation.end());
    sort(bridge.begin(), bridge.end());

    for(auto i:articulation){
        cout << i << endl;
    }
    for(auto i:bridge){
        cout << i.first << " " << i.second << endl;
    }
}