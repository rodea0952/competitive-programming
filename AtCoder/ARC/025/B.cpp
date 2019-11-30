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

    int h, w; cin>>h>>w;
    vector<vector<int>> c(h, vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin>>c[i][j];
    }

    vector<vector<int>> bsum(h+1, vector<int>(w+1, 0));
    vector<vector<int>> wsum(h+1, vector<int>(w+1, 0));

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if((i + j) % 2 == 0){
                bsum[i+1][j+1] = bsum[i+1][j] + c[i][j];
                wsum[i+1][j+1] = wsum[i+1][j];
            }
            else{
                bsum[i+1][j+1] = bsum[i+1][j];
                wsum[i+1][j+1] = wsum[i+1][j] + c[i][j];
            }
        }
    }

    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            bsum[j+1][i+1] += bsum[j][i+1];
            wsum[j+1][i+1] += wsum[j][i+1];
        }
    }

    int ans = 0;
    for(int i1=0; i1<h; i1++){
        for(int j1=0; j1<w; j1++){
            for(int i2=i1; i2<h; i2++){
                for(int j2=j1; j2<w; j2++){
                    int sz = (i2 - i1 + 1) * (j2 - j1 + 1);
                    int bcur = bsum[i2+1][j2+1] - bsum[i1][j2+1] - bsum[i2+1][j1] + bsum[i1][j1];
                    int wcur = wsum[i2+1][j2+1] - wsum[i1][j2+1] - wsum[i2+1][j1] + wsum[i1][j1];

                    if(bcur == wcur) chmax(ans, sz);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}