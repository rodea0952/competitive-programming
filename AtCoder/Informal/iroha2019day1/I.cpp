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

const int MAX_N = 100010;

int n, m, k;
vector<vector<P>> G(MAX_N);
vector<ll> dist(MAX_N, INF);

void dijkstra(int s){
    priority_queue<T, vector<T>, greater<T>> que;
    dist[s] = 0;
    que.push(T(0, 0, s));

    while(!que.empty()){
        int ccost, pvcost, cv;
        tie(ccost, pvcost, cv) = que.top();
        que.pop();

        if(dist[cv] < ccost) continue;

        for(auto x : G[cv]){
            int nv = x.first;
            int nvcost = x.second;

            if(pvcost == 0){
                dist[nv] = 0;
                que.push(T(0, nvcost, nv));
            }
            else if(pvcost == nvcost){
                if(dist[cv] < dist[nv]){
                    dist[nv] = dist[cv];
                    que.push(T(ccost, nvcost, nv));
                }
            }
            else{
                if(dist[cv] + k < dist[nv]){
                    dist[nv] = dist[cv] + k;
                    que.push(T(ccost+k, nvcost, nv));
                }
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--, b--;
        G[a].eb(P(b, c));
        G[b].eb(P(a, c));
    }

    dijkstra(0);

    if(dist[n-1] == INF){
        cout << -1 << endl;
    }
    else{
        cout << dist[n-1] + k << endl;
    }
}