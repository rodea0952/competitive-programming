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
    int x1, y1, x2, y2, x3, y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
    double a = hypot(abs(x1 - x2), abs(y1 - y2));
    double b = hypot(abs(x2 - x3), abs(y2 - y3));
    double c = hypot(abs(x3 - x1), abs(y3 - y1));
    double s = (a + b + c) / 2;
    double S = sqrt(s * (s - a) * (s - b) * (s - c));
    double r = S / s;

    double ok = 0, ng = 1e9;
    double maxedge = max({a, b, c});
    for(int i=0; i<1000; i++){
        double mid = (ok + ng) / 2;

        if(maxedge * (r - mid) / r >= 2 * mid) ok = mid;
        else ng = mid;
    }

    cout << fixed << setprecision(10) << ok << endl;
}