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

int dx[]={1, 1, 0, -1, -1, -1, 0, 1};
int dy[]={0, -1, -1, -1, 0, 1, 1, 1};

int main(){
    while(1){
        int w, h; cin>>w>>h;
        if(w == 0) return 0;

        vector<vector<int>> c(h, vector<int>(w));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>c[i][j];
            }
        }

        int ans=0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(c[i][j]){
                    ans++;
                    c[i][j] = 0;

                    queue<P> que;
                    que.push(P(i, j));
                    while(que.size()){
                        int cy, cx;
                        tie(cy, cx) = que.front();
                        que.pop();

                        for(int k=0; k<8; k++){
                            int ny = cy + dy[k];
                            int nx = cx + dx[k];

                            if(0 <= ny && ny < h && 0 <= nx && nx < w){
                                if(c[ny][nx]){
                                    c[ny][nx] = 0;
                                    que.push(P(ny, nx));
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
}