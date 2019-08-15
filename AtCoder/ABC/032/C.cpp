#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int n, k; cin>>n>>k;
    vector<int> s(n);
    for(int i=0; i<n; i++) cin>>s[i];
    for(int i=0; i<n; i++){
        if(s[i] == 0){
            cout << n << endl;
            return 0;
        }
    }

    if(k == 0){
        cout << 0 << endl;
        return 0;
    }

    int l=0, r=0, ans=0;
    ll pro=1;
    while(r<n){
        pro *= s[r];

        while(pro > k){
            pro /= s[l];
            l++;
        }

        ans = max(ans, r - l + 1);

        r++;
    }
    cout << ans << endl;
}