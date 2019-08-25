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

    int d, g; cin>>d>>g;
    vector<int> p(d), c(d);
    for(int i=0; i<d; i++) cin>>p[i]>>c[i];

    int ans = inf;
    for(int bit=0; bit<(1<<d); bit++){
        int score = 0;
        int cnt = 0;
        for(int i=0; i<d; i++){
            if(bit & (1 << i)){
                score += 100 * (i + 1) * p[i] + c[i];
                cnt += p[i];
            }
        }

        if(score < g){
            for(int i=d-1; i>=0; i--){
                if(!(bit & (1 << i))){
                    for(int j=1; j<=p[i]; j++){
                        score += 100 * (i + 1);
                        cnt++;
                        if(g <= score) break;
                    }
                    break;
                }
            }
        }

        if(g <= score) chmin(ans, cnt);
    }

    cout << ans << endl;
}