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

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<bool> visited(100010);
vector<vector<int>> tree(100010);
vector<vector<int>> G(100010);
vector<int> outdeg(100010);
vector<P> ansedge;

set<P> edge;

void make_tree(int cv){
    visited[cv] = true;

    for(auto nv : G[cv]){
        if(!visited[nv]){
            edge.erase(minmax(cv,nv));
            tree[cv].emplace_back(nv);
            tree[nv].emplace_back(cv);
            make_tree(nv);
        }
    }

    return ;
}

void dfs(int cv, int par){

    for(auto nv : tree[cv]){
        if(nv == par) continue;

        dfs(nv, cv);
    }

    if(cv == 0) return ;

    if(outdeg[cv] % 2){
        ansedge.emplace_back(cv, par);
        outdeg[cv]++;
    }
    else{
        ansedge.emplace_back(par, cv);
        outdeg[par]++;
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        edge.emplace(minmax(a, b));
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    if(m % 2){
        cout << -1 << endl;
        return 0;
    }

    make_tree(0);

    for(auto i : edge){
        outdeg[i.first]++;
        ansedge.emplace_back(i);
    }

    dfs(0, -1);

    for(auto i : ansedge){
        cout << i.first + 1 << " " << i.second + 1 << endl;
    }
}