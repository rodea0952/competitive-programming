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

map<ll, int> prime_factorization(ll n){
    map<ll, int> pcnt;
    ll num = n;
    for(ll i=2; i*i<=n; i++){
        while(num % i == 0){
            num /= i;
            pcnt[i]++;
        }
    }

    if(num != 1){
        pcnt[num]++;
    }

    return pcnt;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin>>n;
    auto pcnt = prime_factorization(n);

    int ans = 0;
    for(auto i : pcnt){
        for(int j=1; j<=i.second; j++){
            ans++;
            i.second -= j;
        }
    }

    cout << ans << endl;

    return 0;
}