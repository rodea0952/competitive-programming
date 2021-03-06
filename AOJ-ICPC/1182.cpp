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

int main(){
    while(1){
        int n, m, c, s, g; cin>>n>>m>>c>>s>>g;
        if(n == 0) return 0;
        s--, g--;
        int dist[c][n][n];
        fill(dist[0][0], dist[c][0], 1e9);
        for(int i=0; i<c; i++){
            for(int j=0; j<n; j++){
                dist[i][j][j] = 0;
            }
        }

        for(int i=0; i<m; i++){
            int x, y, d, com; cin>>x>>y>>d>>com;
            x--, y--, com--;
            dist[com][x][y] = dist[com][y][x] = min(dist[com][x][y], d);
        }

        for(int i=0; i<c; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    for(int l=0; l<n; l++){
                        dist[i][k][l] = min(dist[i][k][l], dist[i][k][j] + dist[i][j][l]);
                    }
                }
            }
        }

        vector<int> p(c);
        for(int i=0; i<c; i++) cin>>p[i];

        vector<vector<int>> fare(c, vector<int>(20010, 0));
        for(int i=0; i<c; i++){
            vector<int> q(p[i]-1);
            vector<int> r(p[i]);
            for(int j=0; j<p[i]-1; j++) cin>>q[j];
            for(int j=0; j<p[i]; j++) cin>>r[j];

            int id = 0;
            for(int j=1; j<=20005; j++){
                if(id < p[i] - 1 && q[id] < j) id++;
                fare[i][j] = fare[i][j-1] + r[id];
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for(int i=0; i<c; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(dist[i][j][k] == 1e9) continue;

                    cost[j][k] = min(cost[j][k], fare[i][dist[i][j][k]]);
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
                }
            }
        }

        cout << (cost[s][g] == 1e9 ? -1 : cost[s][g]) << endl;
    }
}