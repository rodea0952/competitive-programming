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

int n;
const int MAX_V = 10010;

vector<vector<int>> G(MAX_V);
bool visited[MAX_V];
int indeg[MAX_V];
list<int> out;

void bfs(int s){
    queue<int> que;
    que.push(s);
    visited[s] = true;

    while(que.size()){
        int cv = que.front(); que.pop();
        out.push_back(cv);
        for(int i=0; i<G[cv].size(); i++){
            int nv = G[cv][i];
            indeg[nv]--;
            if(indeg[nv] == 0 && !visited[nv]){
                visited[nv] = true;
                que.push(nv);
            }
        }
    }
}

void tsort(){
    for(int i=0; i<n; i++){
        for(int j=0; j<G[i].size(); j++){
            int v = G[i][j];
            indeg[v]++;
        }
    }

    for(int i=0; i<n; i++){
        if(indeg[i] == 0 && !visited[i]) bfs(i);
    }

    for(auto i:out){
        cout << i << endl;
    }
}

int main(){
    int m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int s, t; cin>>s>>t;
        G[s].emplace_back(t);
    }

    tsort();
}