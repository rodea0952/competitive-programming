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

ll dp[110][4][4][4];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<string> base = {"A", "C", "G", "T"};
    
    for(int pp=0; pp<4; pp++){
        for(int p=0; p<4; p++){
            for(int c=0; c<4; c++){
                string cur = base[pp] + base[p] + base[c];
                if(cur == "AGC" || cur == "GAC" || cur == "ACG") continue;

                dp[3][c][p][pp] = 1;
            }
        }
    }

    for(int i=3; i<n; i++){
        for(int ppp=0; ppp<4; ppp++){
            for(int pp=0; pp<4; pp++){
                for(int p=0; p<4; p++){
                    for(int c=0; c<4; c++){
                        string cur = base[pp] + base[p] + base[c];
                        if(cur == "AGC" || cur == "GAC" || cur == "ACG") continue;
                        if(ppp == 0 && p == 2 && c == 3) continue;

                        dp[i+1][c][p][pp] += dp[i][p][pp][ppp];
                        dp[i+1][c][p][pp] %= MOD;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                ans += dp[n][k][j][i];
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}