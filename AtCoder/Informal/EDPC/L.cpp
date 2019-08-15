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

ll dp[3010][3010];

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    for(int len=1; len<=n; len++){
        for(int i=0; i+len<=n; i++){
            int j = i + len;

            // [i, j)
            if((n - len) % 2 == 0){
                // 先手
                // [i+1, j) -> [i, j) と [i, j-1) -> [i, j) の大きい方を取る
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            }
            else{
                // 後手
                // [i+1, j) -> [i, j) と [i, j-1) -> [i, j) の小さい方を取る
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }

    cout << dp[0][n] << endl;
}