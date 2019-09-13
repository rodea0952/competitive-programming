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

vector<ll> prime_factorization(ll n){
    vector<ll> v;
    ll num = n;
    for(int i=2; i*i<=n; i++){
        while(num % i == 0){
            num /= i;
            v.emplace_back(i);
        }
    }

    if(num != 1){
        v.emplace_back(num);
    }

    return v;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    auto v = prime_factorization(n);

    map<int, int> cnt;
    for(auto i : v){
        cnt[i]++;
    }

    int xorsum = 0;
    for(auto i : cnt){
        xorsum ^= i.second;
    }

    if(xorsum != 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;

    return 0;
}