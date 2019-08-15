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
    int n; cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin>>x[i];
    sort(x.begin(), x.end());

    vector<int> dp(1000010, 0);
    for(int i=0; i<n; i++){
        dp[x[i]] = 1;
    }

    for(int i=1; i<1000005; i++){
        if(dp[i]){
            vector<int> v;
            for(int j=1; j*j<=i; j++){
                if(i % j == 0){
                    v.eb(j);
                    v.eb(i / j);
                }
            }

            for(auto j:v){
                if(i != j) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans=0;
    for(int i=0; i<1000005; i++){
        chmax(ans, dp[i]);
    }

    cout << ans << endl;
}