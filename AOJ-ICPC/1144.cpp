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

int ans;
int w, h;

void dfs(int cy, int cx, int depth){
    if(10 <= depth) return;

    for(int i=0; i<4; i++){
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if(0 <= ny && ny < h && 0 <= nx && nx < w && s[ny][nx] != 1){
            while(0 <= ny && ny < h && 0 <= nx && nx < w){
                if(s[ny][nx] == 3){
                    chmin(ans, depth+1);
                    return;
                }
                else if(s[ny][nx] == 1){
                    s[ny][nx] = 0;
                    dfs(ny-dy[i], nx-dx[i], depth+1);
                    s[ny][nx] = 1;
                    break;
                }

                ny += dy[i];
                nx += dx[i];
            }
        }
    }

    return;
}

int main(){
    while(1){
        cin>>w>>h;
        if(w == 0) return 0;
        vector<vector<int>> s(h, vector<int>(w));
        int sy, sx;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>s[i][j];
                if(s[i][j] == 2){
                    sy = i;
                    sx = j;
                    s[i][j] = 0;
                }
            }
        }

        ans = 11;

        dfs(sy, sx, 0);

        cout << ((ans <= 10) ? ans : -1) << endl;
    }
}