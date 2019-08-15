#include <iostream>
#include <vector>
using namespace std;

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;

        vector<vector<int>> t(n, vector<int>(n+1));
        for(int i=0; i<n; i++){
            for(int j=0; j<=n; j++){
                cin>>t[i][j];
            }
        }

        vector<int> dp((1<<n), 1e8);
        dp[0] = 0;

        for(int bit=0; bit<(1<<n); bit++){
            for(int i=0; i<n; i++){
                if((1 << i) & bit) continue;

                int nbit = (1 << i) | bit;

                int tmin = t[i][0];
                for(int j=0; j<n; j++){
                    if((1 << j) & bit){
                        tmin = min(tmin, t[i][j+1]);
                    }
                }

                dp[nbit] = min(dp[nbit], dp[bit] + tmin);
            }
        }

        cout << dp[(1<<n)-1] << endl;
    }
}