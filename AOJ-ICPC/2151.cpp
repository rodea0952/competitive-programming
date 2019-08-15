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

int dijkstra(int s, int g, int l, vector<vector<T>> &G){
    vector<vector<int>> num(110, vector<int>(110, 1e9));
    queue<T> que;
    num[s][l] = 0;
    que.push(T(0, s, l));

    while(!que.empty()){
        int cnum, cv, crest;
        tie(cnum, cv, crest) = que.front();
        que.pop();

        for(auto x : G[cv]){
            int nv, ndist, nnum;
            tie(nv, ndist, nnum) = x;
            
            if(num[cv][crest] < num[nv][crest - ndist] && ndist <= crest){
                num[nv][crest - ndist] = num[cv][crest];
                que.push(T(num[nv][crest - ndist], nv, crest - ndist));
            }
            
            if(num[cv][crest] + nnum < num[nv][crest]){
                num[nv][crest] = num[cv][crest] + nnum;
                que.push(T(num[nv][crest], nv, crest));
            }
        }
    }

    int ans = 1e9;
    for(int i=0; i<=100; i++){
        ans = min(ans, num[g][i]);
    }

    return ans;
}

int main(){
    while(1){
        int n, m, l; cin>>n>>m>>l;
        if(n == 0) return 0;
        vector<vector<T>> G(n);
        for(int i=0; i<m; i++){
            int a, b, d, e; cin>>a>>b>>d>>e;
            a--, b--;
            G[a].eb(T(b, d, e));
            G[b].eb(T(a, d, e));
        }

        cout << dijkstra(0, n-1, l, G) << endl;
    }
}