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
typedef tuple<ll, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={0, 1, 0, -1};
int dy[]={-1, 0, 1, 0};

int main(){
    int h, w, k; cin>>h>>w>>k;
    string d; cin>>d;
    d += d;
    int lU = -1, lR = -1, lD = -1, lL = -1;
    vector<vector<int>> cost(k, vector<int>(4));
    for(int i=2*k-1; i>=0; i--){
        if(d[i] == 'U') lU = i;
        else if(d[i] == 'R') lR = i;
        else if(d[i] == 'D') lD = i;
        else lL = i;

        if(i < k){
            cost[i][0] = lU - i + 1;
            cost[i][1] = lR - i + 1;
            cost[i][2] = lD - i + 1;
            cost[i][3] = lL - i + 1;
        }
    }

    vector<string> s(h);
    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    priority_queue<T, vector<T>, greater<T>> que;
    for(int i=0; i<h; i++){
        cin>>s[i];
        for(int j=0; j<w; j++){
            if(s[i][j] == 'S'){
                dist[i][j] = 0;
                que.push(T(0, i, j));
            }
        }
    }

    ll ans = INF;
    while(que.size()){
        ll cnt;
        int cy, cx;
        tie(cnt, cy, cx) = que.top();
        que.pop();

        if(dist[cy][cx] < cnt) continue;

        int turn = cnt % k;

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            int ncost = cost[turn][i];
            if(ncost <= 0) continue;

            if(0 <= ny && ny < h && 0 <= nx && nx < w){
                if(s[ny][nx] == 'G'){
                    ans = min(ans, dist[cy][cx] + ncost);
                }
                else if(s[ny][nx] == '.'){
                    if(dist[cy][cx] + ncost < dist[ny][nx]){
                        dist[ny][nx] = dist[cy][cx] + ncost;
                        que.push(T(dist[ny][nx], ny, nx));
                    }
                }
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}