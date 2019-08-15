#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
vector<bool> visited(100010, false);
vector<bool> black(100010, false);
vector<bool> white(100010, false);
vector<vector<int>> g(100010);

int bfs(){
    queue<P> que;
    que.push(P(0, 0));
    visited[0]=true;

    while(!que.empty()){
        P q=que.front(); que.pop();
        int now_v=q.first, cost=q.second;

        if(now_v == n-1) return cost;

        for(int i=0; i<g[now_v].size(); i++){
            int nxt_v=g[now_v][i];

            if(visited[nxt_v] == false){
                visited[nxt_v]=true;
                que.push(P(nxt_v, cost+1));
            }
        }
    }
}

void black_paint(int x){
    queue<P> que;
    que.push(P(0, 0));
    black[0]=true;

    while(!que.empty()){
        P q=que.front(); que.pop();
        int now_v=q.first, cost=q.second;

        if(cost == x) continue;

        for(int i=0; i<g[now_v].size(); i++){
            int nxt_v=g[now_v][i];

            if(black[nxt_v] == false){
                black[nxt_v]=true;
                que.push(P(nxt_v, cost+1));
            }
        }
    }
}

int white_paint(){
    queue<int> que;
    que.push(n-1);
    white[n-1]=true;

    int cnt=1;
    while(!que.empty()){
        int now_v=que.front(); que.pop();

        for(int i=0; i<g[now_v].size(); i++){
            int nxt_v=g[now_v][i];

            if(white[nxt_v] == false && black[nxt_v] == false){
                cnt++;
                white[nxt_v]=true;
                que.push(nxt_v);
            }
        }
    }
    return cnt;
}

int main(){
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    black_paint(bfs()/2);

    int white_cnt=white_paint();
    int black_cnt=n-white_cnt;

    if(black_cnt > white_cnt){
        cout << "Fennec" << endl;
    }
    else{
        cout << "Snuke" << endl;
    }
}