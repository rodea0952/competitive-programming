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
    ll l, n; cin>>l>>n;
    vector<ll> x(n+1, 0);
    for(int i=1; i<=n; i++) cin>>x[i];

    vector<ll> xsum(n+10, 0);
    for(int i=1; i<=n; i++){
        xsum[i] = xsum[i-1] + x[i];
    }

    ll dist;
    ll ans = 0;
    for(int i=1; i<=n; i++){
        int m = (i + n + 1) / 2;
        if((i + n) % 2 == 0){
            dist = 2 * (xsum[m] - xsum[i-1]) - x[m] - 2 * (xsum[n] - xsum[m]) + (n - i) * l;
        }
        else{
            dist = 2 * (xsum[m-1] - xsum[i-1]) - 2 * (xsum[n] - xsum[m-1]) + x[m] + (n - i) * l;
        }

        chmax(ans, dist);
    }
    for(int i=1; i<=n; i++){
        int m = (i + 1) / 2;
        if(i % 2 == 0){
            dist = 2 * xsum[m] - x[m] + i * l - 2 * (xsum[i] - xsum[m]);
        }
        else{
            dist = 2 * xsum[m-1] + i * l - 2 * (xsum[i] - xsum[m-1]) + x[m];
        }

        chmax(ans, dist);
    }

    cout << ans << endl;
}