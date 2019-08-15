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

int vcnt;
vector<vector<int>> G(200);
vector<bool> visited(200);

void dfs(int cv){
    vcnt++;
    visited[cv] = true;

    for(auto nv:G[cv]){
        if(!visited[nv]) dfs(nv);
    }

    return;
}

int main(){
    int h, w; cin>>h>>w;
    vector<string> s(h);
    int sv;
    set<int> V;
    for(int i=0; i<h; i++){
        cin>>s[i];
        for(int j=0; j<w; j++){
            if(s[i][j] == 'o'){
                G[i].eb(j+h);
                G[j+h].eb(i);
                sv = i;
                V.insert(i);
                V.insert(j+h);
            }
        }
    }

    dfs(sv);

    int ocnt=0;
    for(int i=0; i<h+w; i++){
        if((int)G[i].size() % 2 == 1) ocnt++;
    }

    if(ocnt <= 2 && vcnt == (int)V.size()){
        cout << "Possible" << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
}