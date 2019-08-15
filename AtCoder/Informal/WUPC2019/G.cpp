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
int dx2[]={1, 1, 0, -1, -1, -1, 0, 1};
int dy2[]={0, -1, -1, -1, 0, 1, 1, 1};

ll cost[15][15];

int main(){
    int n, m; cin>>n>>m;
    vector<int> a(m);
    for(int i=0; i<m; i++) cin>>a[i];
    
    // 定食 i を出したときに、定食 j を待っている人に溜まる不満度
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;

            ll cnti=0;
            ll sumj=0;
            for(int k=m-1; k>=0; k--){
                if(a[k] == i) cnti++;
                if(a[k] == j) sumj+=cnti;
            }

            cost[i][j] = sumj;
        }
    }

    vector<ll> dp(1<<20, INF);
    dp[0]=0;
    for(int S=0; S<(1<<n); S++){
        for(int i=0; i<n; i++){
            if(!(S & (1<<i))){
                ll sum=0;
                for(int j=0; j<n; j++){
                    if(!(S & (1<<j))) sum += cost[i][j];
                }

                dp[S | (1<<i)] = min(dp[S | (1<<i)], dp[S] + sum);
            }
        }
    }

    cout << dp[(1<<n)-1] << endl;
}