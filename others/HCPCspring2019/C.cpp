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
    int n, k; cin>>n>>k;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin>>t[i];

    vector<int> gap(n-1);
    for(int i=0; i<n-1; i++){
        gap[i] = t[i+1] - t[i] - 1;
    }

    sort(gap.begin(), gap.end(), greater<int>());

    ll ans=(t[n-1]+1)-t[0];
    for(int i=0; i<k-1; i++){
        ans -= gap[i];
    }

    cout << ans << endl;
}