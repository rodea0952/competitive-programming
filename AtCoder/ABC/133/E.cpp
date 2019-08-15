#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
#define chmin(a, b) ((a) = min((a), (b)))
#define chmax(a, b) ((a) = max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<bool> visited(100010, false);
vector<vector<int>> G(100010);

ll n, k;
ll ans;

void dfs(int cv, int depth){
    visited[cv] = true;

    int chcnt = 0;
    for(auto nv : G[cv]){
        if(!visited[nv]){
            chcnt++;
            dfs(nv, depth+1);
        }
    }

    if(depth == 0){
        for(int i=0; i<chcnt; i++){
            (ans *= (k - (i + 1))) %= MOD;
        }
    }
    else{
        for(int i=0; i<chcnt; i++){
            (ans *= (k - (i + 2))) %= MOD;
        }
    }

    return ;
}

int main(){
    cin>>n>>k;
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    ans = k;

    dfs(0, 0);

    cout << ans % MOD << endl;
}
