#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n, m; cin>>n>>m;
    vector<vector<P>> g(n);
    vector<int> sl(m);
    for(int i=0; i<m; i++){
        int l, r, d; cin>>l>>r>>d;
        l--, r--;
        sl[i]=l;
        g[l].push_back(P(r, d));
        g[r].push_back(P(l, -d));
    }

    vector<bool> visited(n+10, false);
    for(int i=0; i<m; i++){
        if(visited[sl[i]]) continue;
        visited[sl[i]]=true;

        vector<int> dis(100010, MOD);
        dis[sl[i]]=0;

        queue<int> que;
        que.push(sl[i]);
        while(!que.empty()){
            int nl=que.front(); que.pop();
            visited[nl]=true;

            for(int i=0; i<g[nl].size(); i++){
                if(dis[g[nl][i].first] == MOD){
                    dis[g[nl][i].first] = dis[nl] + g[nl][i].second;
                    que.push(g[nl][i].first);
                }
                else if(dis[nl] + g[nl][i].second != dis[g[nl][i].first]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
}