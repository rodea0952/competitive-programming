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
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> color(210, 0);
bool odd = false;

void dfs(int cv, int pv, vector<vector<int>> &G){

    for(auto nv : G[cv]){
        if(color[nv] != 0){
            if(color[cv] == color[nv]) odd = true;
        }
        else{
            if(color[cv] == 1) color[nv] = 2;
            else color[nv] = 1;

            dfs(nv, cv, G);
        }
    }
    return ;
}


vector<vector<int>> dist(210, vector<int>(210, inf));
void warshall_floyd(int n){
    for(int i=0; i<n; i++) dist[i][i] = 0;

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> G(n);
    
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<n; j++){
            if(s[j] == '1'){
                G[i].emplace_back(j);
                G[j].emplace_back(i);
                dist[i][j] = 1;
                dist[j][i] = 1;
            }
        }
    }

    color[0] = 1;
    dfs(0, -1, G);

    if(odd){
        cout << -1 << endl;
        return 0;
    }

    warshall_floyd(n);

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            chmax(ans, dist[i][j] + 1);
        }
    }

    cout << ans << endl;

    return 0;
}