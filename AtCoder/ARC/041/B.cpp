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

    int n, m; cin>>n>>m;
    int b[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char tmpb; cin>>tmpb;
            b[i][j] = tmpb - '0';
        }
    }

    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int cnt = 0, bmin = 9;
            for(int k=0; k<4; k++){
                int ny = i + dy[k], nx = j + dx[k];
                if(0 <= ny && ny < n && 0 <= nx && nx < m){
                    cnt++;
                    chmin(bmin, b[ny][nx]);
                }
            }

            if(cnt == 4){
                a[i][j] = bmin;
                for(int k=0; k<4; k++){
                    int ny = i + dy[k], nx = j + dx[k];
                    b[ny][nx] -= bmin;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}