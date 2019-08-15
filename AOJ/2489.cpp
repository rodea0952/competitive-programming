#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    int gmax = 1e9;
    int ans;
    for(int i=0; i<=100000; i++){
        vector<int> v;
        int num = i;

        while(num > 0){
            v.emplace_back(num % 10);
            num /= 10;
        }

        int m = v.size();
        bool valid = true;
        for(int j=0; j<m; j++){
            if(v[j] != v[m-1-j]) valid = false;
        }

        if(valid){
            if(abs(n - i) < gmax){
                gmax = abs(n - i);
                ans = i;
            }
        }
    }

    cout << ans << endl;
}