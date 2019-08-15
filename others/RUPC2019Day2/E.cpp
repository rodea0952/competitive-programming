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
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 1, 0, -1, -1, -1, 0, 1};
int dy[]={0, -1, -1, -1, 0, 1, 1, 1};

const int MAX_N=1002000;

vector<vector<P>> g(MAX_N);
vector<ll> dist(MAX_N, INF);
void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s]=0;
    que.push(P(0, s));

    while(!que.empty()){
        P p=que.top(); que.pop();
        ll pcost=p.first, pv=p.second;
        if(dist[pv] < pcost) continue;

        for(int i=0; i<g[pv].size(); i++){
            P p2=g[pv][i];
            ll nv=p2.first, ncost=p2.second;
            if(dist[nv] > dist[pv] + ncost){
                dist[nv] = dist[pv] + ncost;
                que.push(P(dist[nv], nv));
            }
        }
    }
}

int main(){
    int h, w, a, b; cin>>h>>w>>a>>b;
    vector<string> c(h);
    for(int i=0; i<h; i++) cin>>c[i];

    int sy, sx, gy, gx;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(c[i][j]=='s'){
                sy=i, sx=j;
                c[i][j]='.';
            }
            if(c[i][j]=='g'){
                gy=i, gx=j;
                c[i][j]='.';
            }
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            int cur=1000*i+j;

            bool isBomb=false;
            if(c[i][j]=='*') isBomb=true;
            for(int k=0; k<8; k++){
                int ny=i+dy[k], nx=j+dx[k];
                if(0<=ny && ny<h && 0<=nx && nx<w){
                    if(c[ny][nx]=='*') isBomb=true;
                }
            }

            for(int k=0; k<8; k++){
                int ny=i+dy[k], nx=j+dx[k];
                int nxt=1000*ny+nx;
                
                if(0<=ny && ny<h && 0<=nx && nx<w){
                    if(k%2==0){
                        // 上下左右の移動
                        if(c[ny][nx]=='#'){
                            if(isBomb) continue;
                            g[cur].push_back(P(nxt, a+b));
                        }
                        else{
                            g[cur].push_back(P(nxt, a));
                        }
                    }
                    else{
                        // 斜め移動
                        int pny=i+dy[k-1], pnx=j+dx[k-1];
                        int nny=i+dy[(k+1)%8], nnx=j+dx[(k+1)%8];
                        if(c[ny][nx]=='#' || c[pny][pnx]=='#' || c[nny][nnx]=='#'){
                            if(isBomb) continue;
                            g[cur].push_back(P(nxt, 2*a+b));
                        }
                        else{
                            g[cur].push_back(P(nxt, 2*a));
                        }
                    }
                }
            }
        }
    }

    dijkstra(1000*sy+sx);
    
    if(dist[1000*gy+gx]==INF) cout << "INF" << endl;
    else cout << dist[gy*1000+gx] << endl; 
}