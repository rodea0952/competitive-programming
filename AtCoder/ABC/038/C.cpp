#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    ll r=1, l=0, ans=0;
    while(l < n){
        while(a[r-1] < a[r]) r++;
        ans += r-l+1;
        l++;
        r=l+1;
    }
    cout << ans << endl;
}