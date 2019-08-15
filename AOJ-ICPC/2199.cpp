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

int main(){
    while(1){
        int n, m; cin>>n>>m;
        if(n == 0) return 0;
        vector<int> c(m), x(n);
        for(int i=0; i<m; i++) cin>>c[i];
        for(int i=0; i<n; i++) cin>>x[i];

        vector<vector<int>> dp(n+10, vector<int>(300, 1e9));
        dp[0][128] = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<=255; j++){
                for(int k=0; k<m; k++){
                    if(256 <= j + c[k]){
                        dp[i+1][255] = min(dp[i+1][255], dp[i][j] + (x[i] - 255) * (x[i] - 255));
                    }
                    else if(j + c[k] < 0){
                        dp[i+1][0] = min(dp[i+1][0], dp[i][j] + x[i] * x[i]);
                    }
                    else{
                        dp[i+1][j+c[k]] = min(dp[i+1][j+c[k]], dp[i][j] + (x[i] - (j + c[k])) * (x[i] - (j + c[k])));
                    }
                }
            }
        }

        int ans=1e9;
        for(int i=0; i<=255; i++){
            chmin(ans, dp[n][i]);
        }

        cout << ans << endl;
    }
}