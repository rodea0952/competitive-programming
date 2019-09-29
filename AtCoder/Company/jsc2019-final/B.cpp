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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> y(n), x2y(n);
    vector<int> ysz(n);
    for(int i=0; i<n; i++){
        string a; cin>>a;
        // x -> y
        for(int j=0; j<n; j++){
            if(a[j] == '1'){
                y[j].emplace_back(i);
                x2y[i].emplace_back(j);
            }
        }
    }

    for(int i=0; i<n; i++){
        ysz[i] = y[i].size();
    }

    vector<vector<int>> x2z(n);
    vector<vector<int>> judge_x2z(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        string b; cin>>b;
        // x -> z
        for(int j=0; j<n; j++){
            if(b[j] == '1'){
                x2z[i].emplace_back(j);
                judge_x2z[i][j] = 1;
            }
        }
    }

    vector<vector<int>> ycnt(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<y[i].size(); j++){
            for(int k=0; k<x2z[y[i][j]].size(); k++){
                ycnt[i][x2z[y[i][j]][k]]++;
            }
        }
    }

    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<vector<int>> y2z(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ycnt[i][j] == ysz[i]){
                ans[i][j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ans[i][j] == 1){
                y2z[i].emplace_back(j);
            }
        }
    }

    vector<vector<int>> judge_x2z_2(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<x2y[i].size(); j++){
            int nxty = x2y[i][j];
            for(int k=0; k<y2z[nxty].size(); k++){
                judge_x2z_2[i][y2z[nxty][k]] = 1;
            }
        }
    }

    bool valid = true;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(judge_x2z[i][j] != judge_x2z_2[i][j]) valid = false;
        }
    }

    if(!valid) cout << -1 << endl;
    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}