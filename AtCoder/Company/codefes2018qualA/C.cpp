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
    int n, x; cin>>n>>x;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    int ub = min(x, n * 60);

    vector<vector<ll>> dp(n+10, vector<ll>(n*60+10, 0));
    for(int i=0; i<=ub; i++) dp[1][i] = 1;

    for(int i=1; i<n; i++){
        ll sum = a[i] + a[i-1];
        for(int j=0; j<=ub; j++){
            map<ll, bool> used;
            for(int k=0; k<=j; k++){
                ll cnt = j - k;
                if(60 < cnt) continue;
                ll num = (1LL << cnt);

                if(!used[a[i] / num]){
                    used[a[i] / num] = true;
                    (dp[i+1][j] += dp[i][k]) %= MOD;
                }
            }
        }
    }



    cout << dp[n][x] << endl;
}