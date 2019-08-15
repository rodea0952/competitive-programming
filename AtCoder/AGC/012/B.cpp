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

vector<vector<int>> g(100010);
vector<vector<int>> memo(100010, vector<int>(20, 0));

void func(int v, int d, int c){
    if(memo[v][d] != 0) return;
    
    memo[v][d] = c;

    if(d == 0) return;

    func(v, d-1, c);

    for(auto nv:g[v]){
        func(nv, d-1, c);
    }
}

int main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        g[a].eb(b);
        g[b].eb(a);
    }

    int q; cin>>q;
    vector<int> v(q), d(q), c(q);
    for(int i=0; i<q; i++){
        cin>>v[i]>>d[i]>>c[i];
        v[i]--;
    }

    for(int i=q-1; i>=0; i--){
        func(v[i], d[i], c[i]);
    }

    for(int i=0; i<n; i++){
        cout << memo[i][0] << endl;
    }
}