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
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> dp(n+1, 0);
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-1]+abs(a[i]-a[i-1]), dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout << dp[n-1] << endl; 
}