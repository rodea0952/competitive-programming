#pragma GCC optimize("O3")
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
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX_V = 200010;
int V;
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
    cin.tie(0);
    ios::sync_with_stdio(false);

    int M; cin >> V >> M;
    bool valid = true;
    for(int i=0; i<M; i++){
        int k; cin >> k;
        vector<int> a(k);
        set<int> kinds;
        for(int j=0; j<k; j++){
            cin >> a[j];
            a[j]--;
            kinds.emplace(a[j]);
        }

        for(int j=1; j<k; j++){
            add_edge(a[j], a[j - 1]);
        }

        if(kinds.size() != k) valid = false;
    }

    int ans = scc();

    if(!valid){
        cout << "No" << endl;
        return 0;
    }

    cout << (ans == V ? "Yes" : "No") << endl;

    return 0;
}