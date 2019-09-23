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

vector<vector<ll>> dist(60, vector<ll>(60, inf));
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
    vector<int> s(n);
    for(int i=0; i<n; i++) cin>>s[i];
    int m; cin>>m;
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        dist[a][b] = dist[b][a] = c;
    }

    warshall_floyd(n);

    vector<int> v(n, 0);
    v[n-2] = v[n-1] = 1;

    ll ans = INF;
    do{
        vector<int> stay;
        bool valid = true;
        for(int i=0; i<n; i++){
            if(v[i] == 1){
                stay.emplace_back(i);
                if(i == 0 || i == n - 1) valid = false;
            }
        }

        if(!valid) continue;

        ll stay_cost = s[stay[0]] + s[stay[1]];
        ll dist1 = dist[0][stay[0]] + dist[stay[0]][stay[1]] + dist[stay[1]][n-1];
        ll dist2 = dist[0][stay[1]] + dist[stay[1]][stay[0]] + dist[stay[0]][n-1];

        chmin(ans, min(dist1, dist2) + stay_cost);

    }while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
}