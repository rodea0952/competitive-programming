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

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, k;
int ans;
set<vector<string>> grid;

void dfs(vector<string> &s, int cnt){
    if(cnt == k){
        ans++;
        return ;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(s[i][j] != '.') continue;
            bool exist = false;
            for(int di=0; di<4; di++){
                int ni = i + dy[di], nj = j + dx[di];
                if(!(0 <= ni && ni < n && 0 <= nj && nj < n)) continue;
                if(s[ni][nj] == '@') exist = true;
            }

            if(cnt == 0 || exist){
                s[i][j] = '@';
                if(!grid.count(s)){
                    grid.insert(s);
                    dfs(s, cnt + 1);
                }
                s[i][j] = '.';
            }
        }
    }

    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    vector<string> s(n);
    for(int i=0; i<n; i++) cin >> s[i];

    dfs(s, 0);

    cout << ans << endl;

    return 0;
}