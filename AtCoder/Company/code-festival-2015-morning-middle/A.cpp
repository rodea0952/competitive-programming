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

    ll n, k, m, r; cin>>n>>k>>m>>r;
    ll goal = k * r;

    vector<int> s(n, 0);
    for(int i=0; i<n-1; i++) cin>>s[i];
    sort(all(s), greater<int>());

    ll cur = 0;
    for(int i=0; i<k; i++) cur += s[i];

    if(goal <= cur){
        cout << 0 << endl;
        return 0;
    }

    ll cur1 = 0;
    for(int i=0; i<k-1; i++) cur1 += s[i];

    ll rest = goal - cur1;

    if(0 <= rest && rest <= m){
        cout << rest << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}