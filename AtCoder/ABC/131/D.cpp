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
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double pi = acos(-1);
const double eps = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    int n; cin>>n;
    vector<P> v(n);
    for(int i=0; i<n; i++){
        ll a, b; cin>>a>>b;
        v[i] = P(b, a);
    }

    sort(v.begin(), v.end());

    ll sum = 0;
    bool valid = true;
    for(int i=0; i<n; i++){
        sum += v[i].sc;
        if(sum <= v[i].fs);
        else valid = false;
    }

    if(!valid){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}
