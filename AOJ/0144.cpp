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

const int MAX_N = 110;

vector<vector<int>> dist(MAX_N, vector<int>(MAX_N, 1e9));
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
    int n; cin>>n;

    for(int i=0; i<n; i++) dist[i][i] = 0;

    for(int i=0; i<n; i++){
        int r; cin>>r;
        r--;
        int k; cin>>k;
        while(k--){
            int t; cin>>t;
            t--;
            dist[r][t] = 1;
        }
    }

    warshall_floyd(n);

    int q; cin>>q;
    while(q--){
        int s, d, v; cin>>s>>d>>v;
        s--, d--;
        if(dist[s][d] + 1 <= v){
            cout << dist[s][d] + 1 << endl;
        }
        else{
            cout << "NA" << endl;
        }
    }
}