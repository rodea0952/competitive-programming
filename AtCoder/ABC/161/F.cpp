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

    ll n; cin>>n;

    int ans = divisor(n - 1).size();
    
    for(ll i=2; i*i<=n; i++){
        ll cur = n;
        if(cur % i != 0) continue;
        while(cur % i == 0) cur /= i;
        ans += (cur % i == 1);
    }

    cout << ans << endl;

    return 0;
}