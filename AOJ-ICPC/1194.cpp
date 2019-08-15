#include <bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int r, n; cin>>r>>n;
        if(r == 0) return 0;

        vector<int> height(130, 0);

        for(int i=0; i<n; i++){
            int xl, xr, h; cin>>xl>>xr>>h;
            xl += 100;
            xr += 100;

            for(int j=xl; j<xr; j++){
                height[j] = max(height[j], h);
            }
        }

        vector<int> fheight(130, 0);
        for(int i=75; i<=125; i++){
            fheight[i] = min(height[i], height[i-1]);
        }

        double ans = 1e9;
        for(int i=100-r+1; i<100+r; i++){
            double sum = fheight[i] + 1. * (r - sqrt(r * r - abs(100 - i) * abs(100 - i)));
            ans = min(ans, sum);
        }

        printf("%.10f\n", ans);
    }
}