#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int n, q; cin>>n>>q;
    vector<int> a(n+10, 0);
    for(int i=0; i<q; i++){
        int l, r; cin>>l>>r;
        a[l]++, a[r+1]--;
    }
    
    int sum=0;
    for(int i=1; i<=n; i++){
        sum += a[i];
        if(sum % 2 == 0) cout << "0";
        else cout << "1"; 
    }
    cout << endl;
}