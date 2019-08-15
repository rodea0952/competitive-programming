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

void warshall_floyd(int n, vector<vector<int>> &dist){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    while(1){
        int n, m; cin>>n>>m;
        if(n == 0) return 0;

        vector<vector<int>> cost(m, vector<int>(m, 1e9));
        vector<vector<int>> time(m, vector<int>(m, 1e9));
        for(int i=0; i<m; i++){
            cost[i][i] = time[i][i] = 0;
        }

        for(int i=0; i<n; i++){
            int s, t, co, ti; cin>>s>>t>>co>>ti;
            s--, t--;
            cost[s][t] = cost[t][s] = co;
            time[s][t] = time[t][s] = ti;
        }

        warshall_floyd(m, cost);
        warshall_floyd(m, time);

        int q; cin>>q;
        while(q--){
            int s, t, r; cin>>s>>t>>r;
            s--, t--;
            if(r == 0){
                cout << cost[s][t] << endl;
            }
            else{
                cout << time[s][t] << endl;
            }
        }
    }
}