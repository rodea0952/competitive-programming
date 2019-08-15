#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> P;

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;
        map<P, bool> treasure;
        for(int i=0; i<n; i++){
            int x, y; cin>>x>>y;
            treasure[P(x, y)] = true;
        }

        int m; cin>>m;
        int cx = 10, cy = 10;
        for(int i=0; i<m; i++){
            char d; cin>>d;
            int l; cin>>l;
            if(d == 'N'){
                for(int j=0; j<l; j++){
                    cy++;
                    if(treasure[P(cx, cy)]){
                        treasure[P(cx, cy)] = false;
                    }
                }
            }
            else if(d == 'E'){
                for(int j=0; j<l; j++){
                    cx++;
                    if(treasure[P(cx, cy)]){
                        treasure[P(cx, cy)] = false;
                    }
                }
            }
            else if(d == 'S'){
                for(int j=0; j<l; j++){
                    cy--;
                    if(treasure[P(cx, cy)]){
                        treasure[P(cx, cy)] = false;
                    }
                }
            }
            else{
                for(int j=0; j<l; j++){
                    cx--;
                    if(treasure[P(cx, cy)]){
                        treasure[P(cx, cy)] = false;
                    }
                }
            }
        }

        bool valid = true;
        for(auto j : treasure){
            if(j.second) valid = false;
        }

        if(valid){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}