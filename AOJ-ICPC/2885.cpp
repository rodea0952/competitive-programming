#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> dist(1010);

int cntodd, cnteven;
bool valid;

void dfs(int cv, vector<vector<int>> &G){
    for(auto nv:G[cv]){
        if(dist[nv] != -1){
            if(dist[cv] % 2 == dist[nv] % 2){
                valid = false;
                return ;
            }
        }
        else{
            dist[nv] = dist[cv] + 1;
            if(dist[nv] % 2) cntodd++;
            else cnteven++;
            dfs(nv, G);
        }
    }
}

int main(){
    while(1){
        valid = true;
        cntodd = cnteven = 0;
        for(int i=0; i<1010; i++) dist[i] = -1;
        int n, m; cin>>n>>m;
        if(n == 0) return 0;

        vector<vector<int>> G(n);
        for(int i=0; i<m; i++){
            int s, t; cin>>s>>t;
            s--, t--;
            G[s].emplace_back(t);
            G[t].emplace_back(s);
        }

        dist[0] = 0;
        cnteven++;

        dfs(0, G);

        if(!valid){
            cout << 0 << endl;
        }
        else{
            set<int> ans;
            if(cntodd % 2 == 0){
                ans.emplace(cntodd / 2);
            }

            if(cnteven % 2 == 0){
                ans.emplace(cnteven / 2);
            }

            cout << ans.size() << endl;
            for(auto i:ans){
                cout << i << endl;
            }
        }
    }
}