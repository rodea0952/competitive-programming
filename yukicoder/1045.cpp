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

bool can_put[20][5][20][5];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<vector<int>> abc(n, vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) cin>>abc[i][j];
    }

    for(int pi=0; pi<n; pi++){
        for(int ph=0; ph<3; ph++){
            for(int ni=0; ni<n; ni++){
                for(int nh=0; nh<3; nh++){
                    if(pi == ni) continue;

                    vector<int> v1;
                    for(int i=0; i<3; i++){
                        if(i != ph) v1.emplace_back(abc[pi][i]);
                    }

                    vector<int> v2;
                    for(int i=0; i<3; i++){
                        if(i != nh) v2.emplace_back(abc[ni][i]);
                    }

                    sort(all(v1));
                    sort(all(v2));

                    if((v1[0] >= v2[0] && v1[1] >= v2[1]) || (v1[1] >= v2[0] && v1[0] >= v2[1])) can_put[pi][ph][ni][nh] = true;
                }
            }
        }
    }

    vector<vector<vector<int>>> dp((1<<n), vector<vector<int>>(n, vector<int>(3, -1)));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            dp[1<<i][i][j] = abc[i][j];
        }
    }

    for(int bit=0; bit<(1<<n); bit++){
        for(int pi=0; pi<n; pi++){
            for(int ph=0; ph<3; ph++){
                if(dp[bit][pi][ph] == -1) continue;

                for(int ni=0; ni<n; ni++){
                    if(bit & (1 << ni)) continue;

                    for(int nh=0; nh<3; nh++){
                        if(can_put[pi][ph][ni][nh]){
                            chmax(dp[bit | (1 << ni)][ni][nh], dp[bit][pi][ph] + abc[ni][nh]);
                        }
                    }
                }
            }
        }
    }


    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++){
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                chmax(ans, dp[bit][i][j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}