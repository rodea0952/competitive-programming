#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int pa, pb, pc, pd; cin>>pa>>pb>>pc>>pd;
    int ta, tb, tc, td; cin>>ta>>tb>>tc>>td;

    int ans = 1e9;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<=n; k++){
                for(int l=0; l<=n; l++){
                    int tea = i * ta + j * tb + k * tc + l * td;
                    if(n <= tea){
                        ans = min(ans, i * pa + j * pb + k * pc + l * pd);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}