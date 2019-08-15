#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(){
    ll n, m; cin>>n>>m;

    if(n == 1 && m == 1) cout << 1 << endl;
    else if(n == 1) cout << m - 2 << endl;
    else if(m == 1) cout << n - 2 << endl;
    else cout << (n - 2)*(m - 2) << endl;
}