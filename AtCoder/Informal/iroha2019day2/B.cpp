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

bool intersection(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy){
    ll ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    ll tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    ll tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    ll td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);

    return (ta * tb < 0 && tc * td < 0);
}

int main(){
    int x, y, a, b, sx, sy, tx, ty;
    cin>>x>>y>>a>>b>>sx>>sy>>tx>>ty;

    if(intersection(0, a, x, b, sx, sy, tx, ty)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}