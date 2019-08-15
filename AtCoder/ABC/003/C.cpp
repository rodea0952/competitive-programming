#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    int n, k; cin>>n>>k;
    vector<int> r(n);
    for(int i=0; i<n; i++) cin>>r[i];

    sort(r.begin(), r.end());

    double ans=0;
    for(int i=n-k; i<n; i++) ans = (ans + r[i]) / 2;
    cout << fixed << setprecision(10) << ans << endl;
}