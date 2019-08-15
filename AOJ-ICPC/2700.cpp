#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;
        vector<string> s(n);
        for(int i=0; i<n; i++) cin>>s[i];

        for(int k=1; k<=50; k++){
            set<string> cnt;
            for(int i=0; i<n; i++){
                int sz = s[i].size();
                string t;
                t += s[i][0];
                for(int j=1; j<sz; j++){
                    if(s[i][j-1] == 'a' || s[i][j-1] == 'i' || s[i][j-1] == 'u' || s[i][j-1] == 'e' || s[i][j-1] == 'o'){
                        t += s[i][j];
                    }
                }

                if(t.size() < k);
                else t = t.substr(0, k);

                cnt.emplace(t);
            }

            if(cnt.size() == n){
                cout << k << endl;
                goto END;
            }
        }

        cout << -1 << endl;
        END:;
    }
}