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
#define chmin(a, b) ((a) = min((a), (b)))
#define chmax(a, b) ((a) = max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    ll l, r; cin>>l>>r;

    vector<ll> v;
    for(ll i=0; ; i++){
        if((ll)2e9 < i * 2019) break;
        v.emplace_back(i * 2019);
    }

    bool valid = false;
    for(int i=0; i<v.size(); i++){
        if(l <= v[i] && v[i] <= r) valid = true;
    }

    if(valid){
        cout << 0 << endl;
        return 0;
    }

    vector<ll> v2;
    for(ll i=0; ; i++){
        if((ll)2e9 < i * 673) break;
        v2.emplace_back(i * 673);
    }

    valid = false;
    for(int i=0; i<v2.size(); i++){
        if(l <= v2[i] && v2[i] <= r) valid = true;
    }

    bool valid3 = false;
    for(int i=l; i<=min(r, l+2); i++){
        if(i % 3 == 0) valid3 = true;
    }

    if(valid && valid3){
        cout << 0 << endl;
        return 0;
    }

    ll ans = INF;
    for(ll i=l; i<=r; i++){
        for(int j=i+1; j<=r; j++){
            ans = min(ans, (i * j) % 2019);
        }
    }

    cout << ans << endl;
}
