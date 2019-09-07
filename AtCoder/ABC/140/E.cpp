#pragma GCC optimize("O3")
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
using namespace std;

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

template <class T> inline T chmax(T &a, const T b) {return a = (a < b) ? b : a;}
template <class T> inline T chmin(T &a, const T b) {return a = (a > b) ? b : a;}

constexpr int MOD = 1e9 + 7;
constexpr int inf = 1e9;
constexpr long long INF = 1e18;
constexpr double pi = acos(-1);
constexpr double EPS = 1e-10;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> val2index(n);
    for(int i=0; i<n; i++){
        int p; cin>>p;
        p--;
        val2index[p] = i;
    }
    
    multiset<int> st{-1, -1, val2index[n-1], n, n};

    ll ans = 0;
    for(int i=n-2; i>=0; i--){
        st.insert(val2index[i]);

        auto mid = st.find(val2index[i]);
        auto ub = mid; ub++;
        auto uub = ub; uub++;
        auto lb = mid; lb--;
        auto llb = lb; llb--;

        ans += (ll)(*uub - *ub) * (*mid - *lb) * (i + 1);
        ans += (ll)(*lb - *llb) * (*ub - *mid) * (i + 1);
    }

    cout << ans << endl;
}