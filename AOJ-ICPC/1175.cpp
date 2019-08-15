#include <bits/stdc++.h>
using namespace std;

int ans;

void dfs(int sum, int m, vector<int> &cnt, vector<vector<int>> &id, vector<int> &c){
    vector<int> validid(110, true);
    for(int i=0; i<m; i++){
        int idsize = id[i].size();
        for(int j=cnt[i]+1; j<idsize; j++){
            validid[id[i][j]] = false;
        }
    }

    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            if(!(cnt[i] < id[i].size())) continue;
            if(!(cnt[j] < id[j].size())) continue;

            if(!validid[id[i][cnt[i]]]) continue;
            if(!validid[id[j][cnt[j]]]) continue;

            if(c[id[i][cnt[i]]] == c[id[j][cnt[j]]]){
                cnt[i]++;
                cnt[j]++;
                dfs(sum + 2, m, cnt, id, c);
                cnt[i]--;
                cnt[j]--;
            }
        }
    }

    ans = max(ans, sum);
    return ;
}

int main(){
    while(1){
        ans = 0;
        int n; cin>>n;
        if(n == 0) return 0;

        vector<double> x(n), y(n), r(n);
        vector<int> c(n);
        for(int i=0; i<n; i++){
            cin>>x[i]>>y[i]>>r[i]>>c[i];
        }

        vector<vector<int>> id(110);
        id[0].emplace_back(0);
        // j が i より上
        for(int i=1; i<n; i++){
            bool valid = false;
            for(int j=i-1; j>=0; j--){
                double dist = sqrt(abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]));
                if(dist < r[i] + r[j]){
                    valid = true;
                    for(int k=0; k<110; k++){
                        int m = id[k].size();
                        if(m == 0) continue;

                        if(id[k][m-1] == j){
                            id[k].emplace_back(i);
                        }
                    }
                }
            }

            if(!valid){
                for(int k=0; k<110; k++){
                    int m = id[k].size();
                    if(m == 0){
                        id[k].emplace_back(i);
                        break;
                    }
                }
            }
        }

        int m = 0;
        for(int i=0; i<110; i++){
            if(id[i].size() != 0) m++;
        }

        vector<int> cnt(m, 0);

        dfs(0, m, cnt, id, c);

        cout << ans << endl;
    }
}