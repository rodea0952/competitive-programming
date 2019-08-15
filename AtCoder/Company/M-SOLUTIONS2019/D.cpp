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
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

vector<vector<int>> G(10010);
vector<bool> visited(10010);
vector<int> ans(10010), c(10010);
int id;

void dfs(int cv){
    visited[cv] = true;

    ans[cv] = c[id++];

    for(auto nv : G[cv]){
        if(!visited[nv]){
            dfs(nv);
        }
    }

    return ;
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].eb(b);
        G[b].eb(a);
    }

    for(int i=0; i<n; i++) cin>>c[i];

    sort(c.begin(), c.end(), greater<int>());

    int sum = accumulate(c.begin(), c.end(), 0) - c[0];

    dfs(0);

    cout << sum << endl;
    for(int i=0; i<n; i++){
        cout << ans[i] << " \n"[i == n - 1];
    }
}