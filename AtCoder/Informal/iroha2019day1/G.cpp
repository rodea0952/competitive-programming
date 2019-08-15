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
    ll N, M, K; cin>>N>>M>>K;
    vector<ll> a(N);
    for(int i=0; i<N; i++) cin>>a[i];

    if(M * K + (K - 1) < N){
        cout << -1 << endl;
        return 0;
    }

    vector<vector<ll>> dp(400, vector<ll>(400, -1));
    dp[0][0] = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<K; k++){
                if(dp[max(0, i-k)][j] == -1) continue;
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[max(0, i-k)][j] + a[i]);
            }
        }
    }

    ll ans=0;
    for(int i=N-K+1; i<=N; i++){
        chmax(ans, dp[i][M]);
    }

    cout << ans << endl;
}