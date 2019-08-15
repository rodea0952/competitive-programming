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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<ll> sum(n+1, 0);
    for(int i=0; i<n; i++) sum[i+1] = sum[i] + a[i];

    ll ans=INF;
    for(int mid=2; mid<=n-2; mid++){
        ll lsum = sum[mid];
        ll rsum = sum[n] - sum[mid];

        int l = lower_bound(sum.begin(), sum.end(), lsum / 2) - sum.begin();
        int r = lower_bound(sum.begin(), sum.end(), sum[mid] + rsum / 2) - sum.begin();

        ll pqgap = INF;
        ll P, Q;
        for(int i=-1; i<=1; i++){
            ll psum = sum[l+i];
            ll qsum = sum[mid] - psum;

            if(abs(psum - qsum) < pqgap){
                pqgap = abs(psum - qsum);
                P = psum;
                Q = qsum;
            }
        }

        ll rsgap = INF;
        ll R, S;
        for(int i=-1; i<=1; i++){
            ll rsum = sum[r+i] - sum[mid];
            ll ssum = sum[n] - sum[r+i];

            if(abs(rsum - ssum) < rsgap){
                rsgap = abs(rsum - ssum);
                R = rsum;
                S = ssum;
            }
        }

        ll ma = max({P, Q, R, S});
        ll mi = min({P, Q, R, S});

        chmin(ans, ma - mi);
    }

    cout << ans << endl;
}