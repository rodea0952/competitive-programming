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
        int n; cin>>n;
        if(n == 0) return 0;
        vector<vector<int>> dist(20, vector<int>(20, 1e9));
        for(int i=0; i<20; i++){
            dist[i][i] = 0;
        }

        int town=0;
        for(int i=0; i<n; i++){
            int a, b, c; cin>>a>>b>>c;
            dist[a][b] = c;
            dist[b][a] = c;
            chmax(town, max(a, b));
        }

        warshall_floyd(10, dist);

        int ans=1e9;
        int ansid;
        for(int i=0; i<=town; i++){
            int sum=0;
            for(int j=0; j<=town; j++){
                sum += dist[i][j];
            }

            if(sum < ans){
                ans = sum;
                ansid = i;
            }
        }

        cout << ansid << " " << ans << endl;
    }
}