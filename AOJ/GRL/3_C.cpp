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

const int MAX_V = 10010;

int V, E;
vector<vector<int>> G(MAX_V);
vector<vector<int>> rG(MAX_V);
vector<int> vs;
vector<bool> used(MAX_V);
vector<int> cmp(MAX_V);

void add_edge(int from, int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v){
    used[v] = true;
    
    for(int i=0; i<G[v].size(); i++){
        if(!used[G[v][i]]) dfs(G[v][i]);
    }

    vs.push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;

    for(int i=0; i<rG[v].size(); i++){
        if(!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

int scc(){
    for(int i=0; i<MAX_V; i++) used[i] = false;
    vs.clear();
    
    for(int v=0; v<V; v++){
        if(!used[v]) dfs(v);
    }

    for(int i=0; i<MAX_V; i++) used[i] = false;
    int k = 0;

    for(int i=vs.size()-1; i>=0; i--){
        if(!used[vs[i]]) rdfs(vs[i], k++);
    }

    return k;
}

int main(){
    cin>>V>>E;
    for(int i=0; i<E; i++){
        int s, t; cin>>s>>t;
        add_edge(s, t);
    }

    scc();

    int q; cin>>q;
    while(q--){
        int s, t; cin>>s>>t;
        cout << (cmp[s] == cmp[t]) << endl;
    }
}