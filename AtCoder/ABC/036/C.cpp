#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int main() {
    int n; cin>>n;
    vector<int> a(n);
    set<int> s;
    map<int, int> m;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        s.insert(a[i]);
    }

    int cnt=0;
    for(auto x : s){
        m[x] = cnt++;
    }

    for(int i=0; i<n; i++){
        cout << m[a[i]] << endl;
    }
}
