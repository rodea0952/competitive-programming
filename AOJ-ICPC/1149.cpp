#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main(){
    while(1){
        int n, w, h; cin>>n>>w>>h;
        if(w == 0) return 0;

        vector<P> cake;
        cake.emplace_back(w, h);
        for(int i=0; i<n; i++){
            int p, s; cin>>p>>s;
            p--;
            int cw = cake[p].first;
            int ch = cake[p].second;
            cake.erase(cake.begin() + p);

            s %= (cw + ch);

            if(s < cw){
                cake.emplace_back(min(s, cw - s), ch);
                cake.emplace_back(max(s, cw - s), ch);
            }
            else{
                s -= cw;
                cake.emplace_back(cw, min(s, ch - s));
                cake.emplace_back(cw, max(s, ch - s));
            }
        }

        vector<int> ans;
        for(int i=0; i<cake.size(); i++){
            ans.emplace_back(cake[i].first * cake[i].second);
        }

        sort(ans.begin(), ans.end());

        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
    }
}