#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<iomanip>
#include<functional>
using namespace std;

int MOD = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n, k; cin>>n>>k;
    vector<int> d(k);
    for(int i=0; i<k; i++) cin>>d[i];

    for(int i=n; i<MOD; i++){
        int ans=i;
        while(ans>0){
            for(int j=0; j<k; j++){
                if(d[j] == (ans % 10)) goto END;
            }
            ans /= 10;
        }
        cout<<i<<endl;
        return 0;
        END:;
    }
}