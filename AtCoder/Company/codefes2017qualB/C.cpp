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

vector<vector<int>> G(100010);
vector<bool> visited(100010);
vector<int> color(100010, -1);
bool valid = true;
ll wcnt, bcnt;

void dfs(int cv){
    visited[cv] = true;

    for(auto nv : G[cv]){
        if(color[cv] == color[nv]){
            valid = false;
        }

        if(!visited[nv]){
            if(color[cv] == 0){
                color[nv] = 1;
                bcnt++;
            }
            else{
                color[nv] = 0;
                wcnt++;
            }

            dfs(nv);
        }
    }
}

int main(){
    ll n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    wcnt++;
    color[0] = 0;
    dfs(0);

    if(valid){
        cout << wcnt * bcnt - m << endl;
    }
    else{
        cout << n * (n - 1) / 2 - m << endl;
    }
}