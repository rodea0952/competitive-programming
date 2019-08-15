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

const int MAX_V = 210;

int V;
int match[MAX_V];
bool used[MAX_V];
vector<vector<int>> g(MAX_V);
bool dfs(int v){
    used[v] = true;
    for(int i=0; i<g[v].size(); i++){
        int u = g[v][i], w = match[u];

        if(w < 0 || (!used[w] && dfs(w))){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    
    return false;
}

int bipartite_matching(){
    int res = 0;
    memset(match, -1, sizeof(match));

    for(int v=0; v<V; v++){
        if(match[v] < 0){
            memset(used, false, sizeof(used));
            if(dfs(v)){
                res++;
            }
        }
    }

    return res;
}

int main(){
    int x, y, e; cin>>x>>y>>e;
    V = x + y;
    for(int i=0; i<e; i++){
        int s, t; cin>>s>>t;
        g[s].eb(t+100);
        g[t+100].eb(s);
    }

    cout << bipartite_matching() << endl;
}