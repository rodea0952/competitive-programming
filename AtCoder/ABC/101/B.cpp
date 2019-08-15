#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int n; cin>>n;
    int m=n, ans=0;

    while(m>0){
        ans += (m % 10);
        m /= 10;
    }
    
    if(n % ans == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}