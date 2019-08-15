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
    int n, m; cin>>n>>m;
    vector<vector<int>> lb(n), ub(n);
    for(int i=0; i<m; i++){
        int t, l, r; cin>>t>>l>>r;
        l--, r--;
        lb[l].eb(t);
        ub[r].eb(t);
    }

    ll ans=0;
    set<int> st={0};
    for(int i=0; i<n; i++){
        for(auto t : lb[i]) st.insert(t);
        ans += *prev(st.end());
        for(auto t : ub[i]) st.erase(t);
    }

    cout << ans << endl;
}