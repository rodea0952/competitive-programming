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

int B = 0;
int R = 1;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin>>n>>m;
    ll k; cin>>k;
    string s; cin>>s;
    vector<int> color(n);
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'B') color[i] = B;
        else color[i] = R;
    }

    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    if(k % 2 == 1){
        for(int i=0; i<n; i++){
            bool blue_exist = false;
            for(auto j:G[i]){
                if(color[j] == B) blue_exist = true;
            }

            if(blue_exist) cout << "First" << endl;
            else cout << "Second" << endl;
        }
    }
    else{
        vector<bool> adj_red(n, false);
        for(int i=0; i<n; i++){
            bool red_exist = false;
            for(auto j:G[i]){
                if(color[j] == R) red_exist = true;
            }

            adj_red[i] = red_exist;
        }

        for(int i=0; i<n; i++){
            if(color[i] == R){
                cout << "Second" << endl;
                continue;
            }

            bool First_win = false;
            for(auto j:G[i]){
                if(!adj_red[j]) First_win = true;
            }

            if(First_win) cout << "First" << endl;
            else cout << "Second" << endl;
        }
    }
}