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

vector<vector<ll>> accumulation2D(vector<vector<ll>> &v){
    int h = v.size(), w = v[0].size();
    vector<vector<ll>> sum(h+1, vector<ll>(w+1, 0));

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            sum[i+1][j+1] = sum[i+1][j] + v[i][j];
        }
    }

    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            sum[j+1][i+1] += sum[j][i+1];
        }
    }

    return sum;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, k; cin>>h>>w>>k;
    ll v; cin>>v;
    vector<vector<ll>> a(h, vector<ll>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin>>a[i][j];
    }

    auto sum = accumulation2D(a);
    
    ll ans = 0;
    for(int h1=0; h1<h; h1++){
        for(int w1=0; w1<w; w1++){
            for(int h2=h1; h2<h; h2++){
                for(int w2=w1; w2<w; w2++){
                    ll S = (w2 - w1 + 1) * (h2 - h1 + 1);
                    ll cost = sum[h2+1][w2+1] - sum[h1][w2+1] - sum[h2+1][w1] + sum[h1][w1];

                    if(S * k + cost <= v) chmax(ans, S);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
