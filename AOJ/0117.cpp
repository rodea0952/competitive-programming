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

vector<vector<int>> dist(30, vector<int>(30, 1e9));

void warshall_floyd(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<n; i++){
        dist[i][i] = 0;
    }

    char c1, c2, c3;
    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin>>a>>c1>>b>>c2>>c>>c3>>d;
        a--;
        b--;
        dist[a][b] = c;
        dist[b][a] = d;
    }

    int s, g, v, p; cin>>s>>c1>>g>>c2>>v>>c3>>p;
    s--, g--;
    warshall_floyd(n);

    cout << v - p - dist[s][g] - dist[g][s] << endl;
}