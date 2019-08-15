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
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

// A -> 0, G -> 1, C -> 2, T -> 3
ll dp[110][4][4][4];

int main(){
    int n; cin>>n;

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                dp[3][k][j][i] = 1;
            }
        }
    }

    // AGC, ACG, GAC are invalid
    dp[3][2][1][0] = 0;
    dp[3][1][2][0] = 0;
    dp[3][2][0][1] = 0;

    for(int i=3; i<n; i++){
        for(int j=0; j<4; j++){ // i-2
            for(int k=0; k<4; k++){ // i-1
                for(int l=0; l<4; l++){ // i

                    if(dp[i][l][k][j] == 0) continue;

                    for(int m=0; m<4; m++){ // i+1
                        // *AGC 
                        if(k == 0 && l == 1 && m == 2) continue;

                        // *ACG
                        if(k == 0 && l == 2 && m == 1) continue;

                        // *GAC
                        if(k == 1 && l == 0 && m == 2) continue;

                        // A*GC
                        if(j == 0 && l == 1 && m == 2) continue;

                        // AG*C
                        if(j == 0 && k == 1 && m == 2) continue;

                        dp[i+1][m][l][k] += dp[i][l][k][j];
                        dp[i+1][m][l][k] %= MOD;
                    }
                }
            }
        }
    }

    ll ans=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                ans += dp[n][i][j][k];
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;
}