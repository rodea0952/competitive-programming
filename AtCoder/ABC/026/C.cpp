#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int MOD = 1e9 + 7;
ll INF = 1e18;

vector<vector<int>> boss(30);

int dfs(int x){
    if(boss[x].empty()) return 1;

    int maxmoney=0, minmoney=MOD;
    for(auto i : boss[x]){
        int money=dfs(i);
        maxmoney=max(maxmoney, money);
        minmoney=min(minmoney, money);
    }
    return maxmoney + minmoney + 1;
}

int main() {
    int n; cin>>n;
    for(int i=2; i<=n; i++) {
        int b; cin>>b;
        boss[b].push_back(i);
    }

    cout << dfs(1) << endl;
}