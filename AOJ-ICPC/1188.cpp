#include <bits/stdc++.h>
using namespace std;

typedef pair<int, bool> P;

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        int m = s.size();

        int depth = 0;
        vector<vector<P>> v(10010);
        for(int j=0; j<m; j++){
            if(s[j] == '[') depth++;
            else if(s[j] == ']'){
                depth--;
                if(j + 1 < m && s[j+1] == ']'){
                    sort(v[depth].begin(), v[depth].end());
                    int sum = 0;
                    if(v[depth][0].second){
                        for(int k=0; k<v[depth].size()/2+1; k++){
                            sum += (v[depth][k].first + 1) / 2;
                        }
                    }
                    else{
                        for(int k=0; k<v[depth].size()/2+1; k++){
                            sum += v[depth][k].first;
                        }
                    }

                    v[depth].clear();
                    v[depth-1].emplace_back(sum, false);
                }
            }
            else{
                string t;
                t += s[j];
                while(j + 1 < m && '0' <= s[j+1] && s[j+1] <= '9'){
                    j++;
                    t += s[j];
                }

                int num = stoi(t);
                v[depth-1].emplace_back(num, true);
            }
        }

        cout << v[0][0].first << endl;
    }
}