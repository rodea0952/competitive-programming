#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int d, g; cin>>d>>g;
    vector<int> p(d), c(d);
    for(int i=0; i<d; i++) cin>>p[i]>>c[i];

    int MIN=MOD;
    for(int i=0; i<(1<<d); i++){
        int sum=0, cnt=0;

        for(int j=0; j<d; j++){
            
            if(i & (1<<j)){
                sum += p[j] * 100 * (j + 1) + c[j];
                cnt += p[j];
            }
        }

        if(sum >= g) MIN = min(MIN, cnt);
        else{
            for(int j=d-1; j>=0; j--){

                if(!(i & (1<<j))){
                    int cnt2=0;
                    while(sum < g && cnt2 <= p[j]){
                        sum += 100 * (j + 1);
                        cnt++;
                        cnt2++;
                    }
                    break;
                }
            }
            if(sum >= g) MIN = min(MIN, cnt);
        }
    }
    cout << MIN << endl;
}