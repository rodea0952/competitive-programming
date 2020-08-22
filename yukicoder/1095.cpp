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

#define all(a) (a).begin(), (a).end()

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> lmi(n+1, inf), lma(n+1, 0), rmi(n+2, inf), rma(n+2, 0);

    set<int> lnum;
    for(int i=0; i<n; i++){
        lmi[i+1] = min(lmi[i], a[i]);

        auto itr = lnum.lower_bound(a[i]);
        if(itr != lnum.end()) lma[i+1] = *itr;

        lnum.emplace(a[i]);
    }

    set<int> rnum;
    for(int i=n-1; i>=0; i--){
        rmi[i+1] = min(rmi[i+2], a[i]);

        auto itr = rnum.lower_bound(a[i]);
        if(itr != rnum.end()) rma[i+1] = *itr;

        rnum.emplace(a[i]);
    }

    int ans = inf;
    for(int i=1; i<n-1; i++){
        if(lmi[i] < a[i] && a[i] > rmi[i+2]) chmin(ans, lmi[i] + a[i] + rmi[i+2]);
        if(lma[i+1] > a[i] && a[i] < rma[i+1]) chmin(ans, lma[i+1] + a[i] + rma[i+1]);
    }

    cout << (ans == inf ? -1 : ans) << endl;

    return 0;
}