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
    int n, q; cin>>n>>q;
    vector<T> X(n);
    for(int i=0; i<n; i++){
        int s, t, x; cin>>s>>t>>x;
        X[i] = T(x, s - x, t - x);
    }

    sort(X.begin(), X.end());

    set<P> st;
    for(int i=0; i<q; i++){
        int d; cin>>d;
        st.insert(P(d, i));
    }

    vector<int> ans(q, -1);
    for(int i=0; i<n; i++){
        int x, s, t;
        tie(x, s, t) = X[i];
        auto itr = st.lower_bound(P(s, -1));

        while(itr != st.end()){
            if(t <= itr->first) break;

            ans[itr->second] = x;
            st.erase(itr++);
        }
    }

    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }
}