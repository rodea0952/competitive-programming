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

int n;
double dp[310][310][310];

double rec(int x, int y, int z){
    if(dp[x][y][z] != -1) return dp[x][y][z];
    if(x == 0 && y == 0 && z == 0) return 0.0;

    double res = 0.0;
    if(x > 0) res += rec(x-1, y, z) * x;
    if(y > 0) res += rec(x+1, y-1, z) * y;
    if(z > 0) res += rec(x, y+1, z-1) * z;
    res += n;
    res *= 1.0 / (x + y + z);

    return dp[x][y][z] = res;
}

int main(){
    cin>>n;
    vector<int> cnt(4, 0);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        cnt[x]++;
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<=n; k++){
                dp[i][j][k] = -1;
            }
        }
    }

    cout << fixed << setprecision(12) << rec(cnt[1], cnt[2], cnt[3]) << endl;
}