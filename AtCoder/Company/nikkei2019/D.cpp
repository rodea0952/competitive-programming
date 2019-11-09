#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int n;
const int MAX_V=100010;

vector<vector<int>> g(MAX_V);
vector<vector<int>> rev(MAX_V);
vector<int> revv;
bool visited[MAX_V];
int indeg[MAX_V];
int parent[MAX_V];
vector<int> out;
int st;

void bfs(int s){
    st=s;
    queue<int> que;
    que.push(s);
    visited[s]=true;

    while(que.size()){
        int cv=que.front(); que.pop();
        out.push_back(cv);
        for(int i=0; i<g[cv].size(); i++){
            int nv=g[cv][i];
            indeg[nv]--;
            if(indeg[nv]==0 && !visited[nv]){
                visited[nv]=true;
                parent[nv]=cv;
                que.push(nv);
            }
        }
    }
}

void tsort(){
    for(int i=0; i<n; i++){
        for(int j=0; j<g[i].size(); j++){
            int v=g[i][j];
            indeg[v]++;
        }
    }

    for(int i=0; i<n; i++){
        if(indeg[i]==0 && !visited[i]) bfs(i);
    }
}

int main(){
    int m; cin>>n>>m;
    for(int i=0; i<n+m-1; i++){
        int x, y; cin>>x>>y;
        x--, y--;
        g[x].eb(y);
        rev[y].eb(x);
    }

    tsort();
    
    for(int i=0; i<n; i++){

        if(i==st) cout << 0 << endl;
        else cout << parent[i]+1 << endl;
    }
}
