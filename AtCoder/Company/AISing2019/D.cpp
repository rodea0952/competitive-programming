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
    int n, q; cin>>n>>q;
    vector<int> a(n);
    vector<ll> sum(n+10, 0), divsum(n+10, 0);
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum[i+1] = sum[i] + a[i];
        divsum[i+1] = a[i];
        if(2 <= i) divsum[i+1] += divsum[i-1]; 
    }

    for(int i=0; i<q; i++){
        int x; cin>>x;
        int ng = 0, ok = n - 1;
        int ub, lb;
        while(ok - ng > 1){
            int mid = (ng + ok) / 2;

            if(a[mid] < x){
                ng = mid;
            }
            else{
                ub = n - mid;
                lb = lower_bound(a.begin(), a.end(), a[mid]) - lower_bound(a.begin(), a.end(), 2 * x - a[mid]) + 1;

                if(lb < ub) ng = mid;
                else ok = mid;
            }
        }

        ll ans = sum[n] - sum[ok];
        int Tturn = n - (n - ok) * 2;
        ans += divsum[max(Tturn, 0)];

        cout << ans << endl;
    }
}