#pragma GCC optimize("O3")
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
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int MAX_V = 300;

vector<int> depth(MAX_V);
vector<vector<int>> G(MAX_V);

void calc_depth(int cv, int dep){
    depth[cv] = dep;
    for(auto nv : G[cv]){
        calc_depth(nv, dep + 1);
    }

    return ;
}

vector<int> tmp_depth;
vector<bool> used(MAX_V);

void can_reach(int cv, int dep){
    if(used[cv]) return ;

    tmp_depth.emplace_back(dep);
    for(auto nv : G[cv]){
        can_reach(nv, dep + 1);
    }

    return ;
}

void go_to_child(int cv){
    used[cv] = true;

    for(auto nv : G[cv]){
        go_to_child(nv);
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, k; cin>>n>>m>>k;
    int root;
    for(int i=0; i<n; i++){
        int p; cin>>p;
        p--;
        if(p == -1){
            root = i;
            continue;
        }
        G[p].emplace_back(i);
    }

    calc_depth(root, 1);

    vector<int> ans;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!used[j]){
                used[j] = true;

                tmp_depth.clear();
                can_reach(root, 1);

                int nxtneed = m - i - 1;

                if(tmp_depth.size() < nxtneed){
                    used[j] = false;
                    continue;
                }

                sort(tmp_depth.begin(), tmp_depth.end());

                int nxtmin = 0;
                for(int l=0; l<nxtneed; l++){
                    nxtmin += tmp_depth[l];
                }

                reverse(tmp_depth.begin(), tmp_depth.end());
                int nxtmax = 0;
                for(int l=0; l<nxtneed; l++){
                    nxtmax += tmp_depth[l];
                }

                if(nxtmin <= k - depth[j] && k - depth[j] <= nxtmax){
                    ans.emplace_back(j);
                    k -= depth[j];
                    go_to_child(j);
                    break;
                }
                else{
                    used[j] = false;
                }
            }
        }
    }

    if(ans.size() != m){
        cout << -1 << endl;
    }
    else{
        for(int i=0; i<m; i++){
            cout << ans[i] + 1 << " \n"[i == m-1];
        }
    }
}