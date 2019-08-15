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

vector<vector<P>> G(20);
vector<bool> visited(20);

int tsum;
int chsum;
int ans = 1e9;

void dfs(int cv, int ptime){
    visited[cv] = true;

    bool haveChild = false;

    for(auto x : G[cv]){
        int nv, ntime;
        tie(nv, ntime) = x;

        if(!visited[nv]){
            haveChild = true;
            dfs(nv, ntime);
        }
    }

    if(!haveChild){
        chsum += ptime;
    }
}

void dfs2(int cv, int sum, int ptime){
    visited[cv] = true;

    bool haveChild = false;

    for(auto x : G[cv]){
        int nv, ntime;
        tie(nv, ntime) = x;

        if(!visited[nv]){
            haveChild = true;
            dfs2(nv, sum + ntime, ntime);
        }
    }

    if(!haveChild){
        ans = min(ans, tsum * 2 - (sum - ptime));
    }
}

int main(){
    while(1){
        int n; cin>>n;
        if(n == 0) return 0;
        for(int i=0; i<n-1; i++){
            int a, b, t; cin>>a>>b>>t;
            a--, b--;
            G[a].emplace_back(b, t);
            G[b].emplace_back(a, t);
            tsum += t;
        }

        dfs(0, 0);
        tsum -= chsum;
        for(int i=0; i<20; i++){
            visited[i] = false;
        }

        dfs2(0, 0, 0);

        cout << ans << endl;

        tsum = 0;
        chsum = 0;
        ans = 1e9;
        for(int i=0; i<20; i++){
            G[i].clear();
            visited[i] = false;
        }
    }
}