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
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    int n; cin>>n;
    vector<P> c(n);
    for(int i=0; i<n; i++){
        cin>>c[i].fs>>c[i].sc;
    }

    sort(c.begin(), c.end());

    vector<ll> vsum(n+10, 0);
    vsum[0] = c[0].sc;
    for(int i=1; i<n; i++){
        vsum[i] = vsum[i-1] + c[i].sc;
    }

    vector<ll> bestmin(n+10, 0);
    bestmin[0] = vsum[0] - c[0].fs - c[0].sc;
    for(int i=1; i<n; i++){
        bestmin[i] = min(bestmin[i-1], vsum[i] - c[i].fs - c[i].sc);
    }

    ll ans=c[0].sc;
    for(int i=1; i<n; i++){
        ll sum = (vsum[i] - c[i].fs) - (bestmin[i]);
        chmax(ans, sum);
    }

    cout << ans << endl;
}