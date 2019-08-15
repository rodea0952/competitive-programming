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

int maxDepth;
int w, h;

void dfs(int cy, int cx, int depth, vector<vector<int>> &ice){
    ice[cy][cx] = 0;

    chmax(maxDepth, depth);

    if(0 <= cx - 1 && ice[cy][cx-1]){
        dfs(cy, cx-1, depth+1, ice);
    }
    if(cx + 1 < w && ice[cy][cx+1]){
        dfs(cy, cx+1, depth+1, ice);
    }
    if(0 <= cy - 1 && ice[cy-1][cx]){
        dfs(cy-1, cx, depth+1, ice);
    }
    if(cy + 1 < h && ice[cy+1][cx]){
        dfs(cy+1, cx, depth+1, ice);
    }

    ice[cy][cx] = 1;
}

int main(){
    while(1){
        cin>>w>>h;
        if(w == 0) return 0;

        vector<vector<int>> ice(h, vector<int>(w));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>ice[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(ice[i][j]){
                    dfs(i, j, 1, ice);
                }
            }
        }

        cout << maxDepth << endl;

        maxDepth = 0;
    }
}