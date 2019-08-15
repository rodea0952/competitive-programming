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

vector<vector<ll>> dist(110, vector<ll>(110, INF));
bool valid = true;

void warshall_floyd(int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }

                if(i == j && dist[i][j] < 0){
                    valid = false;
                }
            }
        }
    }
}

int main(){
    int v, e; cin>>v>>e;

    for(int i=0; i<v; i++){
        dist[i][i] = 0;
    }

    for(int i=0; i<e; i++){
        int s, t, d; cin>>s>>t>>d;
        dist[s][t] = d;
    }

    warshall_floyd(v);

    if(!valid){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(dist[i][j] == INF) cout << "INF" << " \n"[j == v-1]; 
            else cout << dist[i][j] << " \n"[j == v-1];
        }
    }
}