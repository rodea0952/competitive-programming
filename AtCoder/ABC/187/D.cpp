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
    vector<tuple<ll, int, int>> ab;
    ll ao = 0;
    for(int i=0; i<n; i++){
        ll a, b; cin>>a>>b;
        ab.emplace_back(2 * a + b, a, b);
        ao += a;
    }

    sort(all(ab));
    reverse(all(ab));

    ll ta = 0;
    for(int i=0; i<n; i++){
        ll num, a, b; tie(num, a, b) = ab[i];
        ta += a + b;
        ao -= a;
        if(ao < ta){
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}