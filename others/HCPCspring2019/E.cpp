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

int dp[100010][5];

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    dp[1][0] = 1;
    dp[1][1] = 1;
    int ans=0;
    for(int i=1; i<n; i++){
        if(a[i] != a[i-1]){
            dp[i+1][0] = dp[i][0] + 1;
            dp[i+1][1] = dp[i][1] + 1;
            dp[i+1][2] = dp[i][2] + 1;
        }
        if(a[i] == a[i-1]){
            dp[i+1][0] = 1;
            dp[i+1][1] = dp[i][0] + 1;
            dp[i+1][2] = dp[i][1] + 1;
        }

        chmax(ans, max(dp[i+1][0], dp[i+1][2]));
    }

    cout << ans << endl;
}