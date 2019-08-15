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
        int w, h; cin>>w>>h;
        if(w == 0) return 0;
        vector<string> a(h);
        for(int i=0; i<h; i++) cin>>a[i];

        int BS = 0, WS = 0;
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(a[i][j] == '.' && !visited[i][j]){
                    visited[i][j] = true;
                    queue<P> que;
                    que.push(P(i, j));
                    int S = 1;
                    bool isW = false, isB = false;
                    while(que.size()){
                        int cy, cx;
                        tie(cy, cx) = que.front();
                        que.pop();

                        for(int k=0; k<4; k++){
                            int ny = cy + dy[k];
                            int nx = cx + dx[k];

                            if(0 <= ny && ny < h && 0 <= nx && nx < w){
                                if(!visited[ny][nx] && a[ny][nx] == '.'){
                                    S++;
                                    visited[ny][nx] = true;
                                    que.push(P(ny, nx));
                                }
                                if(a[ny][nx] == 'W') isW = true;
                                if(a[ny][nx] == 'B') isB = true;
                            }
                        }
                    }

                    if(!isW && isB) BS += S;
                    if(isW && !isB) WS += S;
                }
            }
        }

        cout << BS << " " << WS << endl;
    }
}