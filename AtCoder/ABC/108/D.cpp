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
    ll l; cin>>l;

    ll r=30;
    while((1LL << r) > l){
        r--;
    }

    vector<T> edge;
    for(ll i=0; i<r; i++){
        ll cost = (1LL << i);
        edge.eb(T(i+1, i+2, cost));
        edge.eb(T(i+1, i+2, 0));
    }

    for(ll i=r; i>=1; i--){
        ll cntpath = (1LL << (i - 1));
        if(cntpath + (1LL << r) <= l){
            edge.eb(T(i, r+1, l-cntpath));
            l -= cntpath;
        }
    }

    cout << r+1 << " " << edge.size() << endl;
    for(auto i:edge){
        cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    }
}