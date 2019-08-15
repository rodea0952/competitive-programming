#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<ll> dis(100010, 0);
vector<vector<P>> tree(100010);

void bfs(int k){
    dis[k]=-1;
    queue<P> que;
    que.push(P(k, 0));

    while(!que.empty()){
        P q=que.front(); que.pop();
        int now_v=q.first;
        ll now_cost=q.second;

        for(int i=0; i<tree[now_v].size(); i++){
            int next_v=tree[now_v][i].first;
            ll path_cost=tree[now_v][i].second;

            if(dis[next_v] == 0){
                dis[next_v]=now_cost+path_cost;
                que.push(P(next_v, dis[next_v]));
            }
        }
    }
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n-1; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        tree[a].push_back(P(b, c));
        tree[b].push_back(P(a, c));
    }

    int q, k; cin>>q>>k;
    k--;
    bfs(k);
    for(int i=0; i<q; i++){
        int x, y; cin>>x>>y;
        x--, y--;
        cout << dis[x] + dis[y] << endl;
    }
}