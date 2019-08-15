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
typedef pair<double, double> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
const double eps=1e-10;

int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};

int main(){
    int n; cin>>n;
    vector<P> xr;
    for(int i=0; i<n; i++){
        double x, r; cin>>x>>r;
        xr.eb(P(x, r));
    }
    sort(xr.begin(), xr.end());

    double ans = max(xr[0].sc, xr[1].sc);
    double c1 = max((double)0, (xr[0].sc - (xr[1].fs - xr[0].fs))) * (xr[0].sc - (xr[1].fs - xr[0].fs)) * (xr[0].sc - (xr[1].fs - xr[0].fs));
    double c2 = xr[1].sc * xr[1].sc * xr[1].sc;
    double cr = pow((c1 + c2), 1. / 3);

    chmax(ans, cr);

    cout << fixed << setprecision(10) << ans << endl;
}