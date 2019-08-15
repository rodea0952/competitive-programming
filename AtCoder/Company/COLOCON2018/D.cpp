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

int dp[5010][5010];

int main(){
    int n, x; cin>>n>>x;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin>>t[i];

    dp[0][0] = x;
    for(int i=0; i<n; i++){
        
        // t[j] <= t[i] + x
        int j=0;
        for(j=i; j+1<n && t[j+1] <= t[i] + x; j++);

        for(int k=0; k<n; k++){
            dp[j][k+1] = max(dp[j][k+1], dp[i][k] + min(x, t[j] - t[i]));
        
            if(j + 1 < n){
                dp[j+1][k+1] = max(dp[j+1][k+1], dp[i][k] + min(x, t[j+1] - t[i]));
            }
        }
    }

    for(int i=0; i<n; i++){
        int ans=0;
        for(int j=0; j<=n; j++){
            chmax(ans, dp[j][i]);
        }

        cout << ans << endl;
    }
}