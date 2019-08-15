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

int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x % y);
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> l(n, a[0]), r(n, a[n-1]);
    for(int i=1; i<n; i++){
        l[i] = gcd(a[i], l[i-1]);
        r[n-1-i] = gcd(a[n-1-i], r[n-i]);
    }

    int ans=max(l[n-2], r[1]);
    for(int i=1; i<n-1; i++){
        int num = gcd(l[i-1], r[i+1]);
        chmax(ans, num);
    }

    cout << ans << endl;
}