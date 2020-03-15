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

vector<ll> prime_factorization(ll n){
    vector<ll> v;
    ll num = n;
    for(ll i=2; i*i<=n; i++){
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
    map<int, int> cnt;
    for(int i=2; i<=n; i++){
        auto v = prime_factorization(i);
        for(auto j : v) cnt[j]++;
    }

    for(auto i : cnt) cnt[i.first]++;

    int ans = 0;
    // 1 * 75
    for(auto i : cnt){
        if(75 <= i.second) ans++;
    }

    // 3 * 25
    for(auto i : cnt){
        for(auto j : cnt){
            if(i.first == j.first) continue;
            if(3 <= i.second && 25 <= j.second) ans++;
        }
    }

    // 5 * 15
    for(auto i : cnt){
        for(auto j : cnt){
            if(i.first == j.first) continue;
            if(5 <= i.second && 15 <= j.second) ans++;
        }
    }

    // 3 * 5 * 5
    for(auto i : cnt){
        for(auto j : cnt){
            for(auto k : cnt){
                if(i.first == j.first) continue;
                if(j.first == k.first) continue;
                if(k.first == i.first) continue;
                if(j.first > k.first) continue;
                if(3 <= i.second && 5 <= j.second && 5 <= k.second) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}