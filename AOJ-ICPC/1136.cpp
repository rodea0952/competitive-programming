#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;

        vector<int> ans;
        vector<vector<P>> base(4);
        for(int i=0; i<=n; i++){
            int m; cin>>m;
            
            vector<int> x(m), y(m);
            for(int j=0; j<m; j++) cin>>x[j]>>y[j];

            if(i == 0){
                for(int j=0; j<m-1; j++){
                    int dx = x[j+1] - x[j];
                    int dy = y[j+1] - y[j];

                    base[0].emplace_back(dx, dy);
                }

                for(int j=1; j<4; j++){
                    for(int k=0; k<m-1; k++){
                        int pdx = base[j-1][k].first;
                        int pdy = base[j-1][k].second;
                        if(pdx == 0){
                            base[j].emplace_back(pdy, pdx);
                        }
                        else{
                            base[j].emplace_back(pdy, -pdx);
                        }
                    }
                }
            }
            else{
                if(m != base[0].size() + 1){
                    continue;
                }

                for(int j=0; j<4; j++){
                    bool same = true;
                    for(int k=0; k<m-1; k++){
                        int dx = x[k+1] - x[k];
                        int dy = y[k+1] - y[k];

                        if(!(base[j][k].first == dx && base[j][k].second == dy)){
                            same = false;
                        }
                    }

                    if(same){
                        ans.emplace_back(i);
                        break;
                    }

                    same = true;
                    for(int k=m-2; k>=0; k--){
                        int dx = x[k] - x[k+1];
                        int dy = y[k] - y[k+1];

                        if(!(base[j][m-2-k].first == dx && base[j][m-2-k].second == dy)){
                            same = false;
                        }
                    }

                    if(same){
                        ans.emplace_back(i);
                        break;
                    }
                }
            }
        }

        for(auto i:ans) cout << i << endl;
        cout << "+++++" << endl;
    }
}