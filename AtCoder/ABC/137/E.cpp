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

const int MAX_V = 2500;

vector<T> edge;
vector<ll> dist(MAX_V);
int n, m, p;

vector<ll> bellman_ford(int s, int loop_num){
    for(int i=0; i<n; i++) dist[i] = INF;
    dist[s] = 0;
    
    for(int i=0; i<loop_num; i++){
        for(int j=0; j<edge.size(); j++){
            int cv, nv, cost;
            tie(cv, nv, cost) = edge[j];

            if(dist[cv] != INF && dist[nv] > dist[cv] + cost){
                dist[nv] = dist[cv] + cost;
            }
        }
    }

    return dist;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>m>>p;
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        edge.emplace_back(a, b, p - c);
    }

    auto dist1 = bellman_ford(0, n - 1);
    auto dist2 = bellman_ford(0, 2 * (n - 1));

    if(dist1[n - 1] != dist2[n - 1]){
        cout << -1 << endl;
    }
    else{
        cout << max(0LL, -dist1[n - 1]) << endl;
    }
}