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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, d, e, f; cin>>a>>b>>c>>d>>e>>f;

    double ma = -1;
    P ans;
    for(int i=0; i<=f; i+=100*a){
        for(int j=0; i+j<=f; j+=100*b){
            for(int k=0; i+j+k<=f; k+=c){
                for(int l=0; i+j+k+l<=f; l+=d){
                    if((i + j) / 100 * e < k + l) continue;

                    if(ma < 1. * (k + l) * 100 / (i + j + k + l)){
                        ma = 1. * (k + l) * 100 / (i + j + k + l);
                        ans = P(i + j + k + l, k + l);
                    }
                }
            }
        }
    }

    cout << ans.first << " " << ans.second << endl;

    return 0;
}