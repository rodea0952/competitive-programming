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
    int x=101, ans=0;
    for(int i=0; i<n-1; i++) {
        if(a[i]==a[i+1]) a[i+1]=x, x++, ans++;
    }
    cout<<ans<<endl;
}