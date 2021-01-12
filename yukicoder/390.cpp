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

vector<ll> divisor(ll n){
    vector<ll> v;
    for(ll i=1; i*i<=n; i++){
        if(n % i == 0){
            v.emplace_back(i);
            v.emplace_back(n / i);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    return v;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin>>x[i];

    sort(all(x));

    vector<int> dp(1000010, 0);
    for(int i=0; i<n; i++){
        auto div = divisor(x[i]);
        int ma = 0;
        for(auto j:div){
            chmax(ma, dp[j] + 1);
        }
        dp[x[i]] = ma;
    }

    cout << *max_element(all(dp)) << endl;

    return 0;
}