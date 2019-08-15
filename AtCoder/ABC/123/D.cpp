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
    int x, y, z, k; cin>>x>>y>>z>>k;
    vector<ll> a(x), b(y), c(z);
    for(int i=0; i<x; i++) cin>>a[i];
    for(int i=0; i<y; i++) cin>>b[i];
    for(int i=0; i<z; i++) cin>>c[i];

    sort(a.rbegin(), a.rend());
    
    vector<ll> bc;
    for(int i=0; i<y; i++){
        for(int j=0; j<z; j++){
            bc.eb(b[i] + c[j]);
        }
    }

    sort(bc.rbegin(), bc.rend());
    if(k < bc.size()) bc.resize(k);

    vector<ll> ans;
    for(int i=0; i<x; i++){
        for(int j=0; j<bc.size(); j++){
            ans.eb(a[i] + bc[j]);
        }
    }

    sort(ans.rbegin(), ans.rend());

    for(int i=0; i<k; i++){
        cout << ans[i] << endl;
    }
}