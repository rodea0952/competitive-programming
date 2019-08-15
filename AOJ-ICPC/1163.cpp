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

const int MAX_V = 1010;

int match[MAX_V];
bool used[MAX_V];
vector<vector<int>> G(MAX_V);

bool dfs(int v){
    used[v] = true;
    for(int i=0; i<G[v].size(); i++){
        int u = G[v][i], w = match[u];

        if(w < 0 || (!used[w] && dfs(w))){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    
    return false;
}

int bipartite_matching(int V){
    int res = 0;
    memset(match, -1, sizeof(match));
    memset(used, 0, sizeof(used));

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
    while(1){
        int m, n; cin>>m>>n;
        if(m == 0) return 0;

        vector<int> a(m), b(n);
        for(int i=0; i<m; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];

        int V = m + n;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(__gcd(a[i], b[j]) != 1){
                    int from = i;
                    int to = m + j;

                    G[from].emplace_back(to);
                    G[to].emplace_back(from);
                }
            }
        }

        cout << bipartite_matching(V) << endl;

        for(int i=0; i<V; i++){
            G[i].clear();
        }
    }
}