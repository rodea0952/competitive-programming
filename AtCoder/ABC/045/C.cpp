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
    while(1){
        string s; cin>>s;
        if(s == "0") break;
        int n=s.size();

        ll ans=0;
        for(int bit=0; bit<(1<<n-1); bit++){
            ll tmp=(s[0]-'0'), sum=0;
            for(int i=0; i<n-1; i++){
                if(bit & (1<<i)){
                    sum+=tmp;
                    tmp=0;
                }
                tmp=tmp*10+(s[i+1]-'0');
            }
            ans+=tmp+sum;
        }
        cout<<ans<<endl;
    }
}