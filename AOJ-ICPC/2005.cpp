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

int main(){
    while(1){
        int n, m, s, g1, g2; cin>>n>>m>>s>>g1>>g2;
        s--, g1--, g2--;
        if(n == 0) return 0;

        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for(int i=0; i<n; i++) dist[i][i] = 0;
        for(int i=0; i<m; i++){
            int b1, b2, c; cin>>b1>>b2>>c;
            b1--, b2--;
            dist[b1][b2] = c;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int ans = 1e8;
        for(int i=0; i<n; i++){
            ans = min(ans, dist[s][i] + dist[i][g1] + dist[i][g2]);
        }

        cout << ans << endl;
    }
}