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
typedef tuple<int, int, int, vector<vector<int>>> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    vector<vector<int>> num(4, vector<int>(4));
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            num[i][j] = i * 4 + j;
        }
    }

    map<vector<vector<int>>, int> cnt;
    map<vector<vector<int>>, bool> used;
    cnt[num] = 0;
    used[num] = true;
    queue<T> que;
    que.push(T(0, 0, 0, num));
    while(que.size()){
        int cy, cx, cost;
        vector<vector<int>> cnum(4, vector<int>(4));
        tie(cy, cx, cost, cnum) = que.front();
        que.pop();

        for(int i=0; i<4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(0 <= ny && ny < 2 && 0 <= nx && nx < 4){
                swap(cnum[cy][cx], cnum[ny][nx]);
                if(!used[cnum]){
                    used[cnum] = true;
                    cnt[cnum] = cost + 1;
                    que.push(T(ny, nx, cost + 1, cnum));
                }
                swap(cnum[cy][cx], cnum[ny][nx]);
            }
        }
    }

    vector<vector<int>> v(4, vector<int>(4));
    while(cin>>v[0][0]){
        for(int i=1; i<4; i++) cin>>v[0][i];
        for(int i=0; i<4; i++) cin>>v[1][i];

        cout << cnt[v] << endl;
    }
}