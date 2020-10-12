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

ll n, k, m;

vector<ll> prime_factorization(ll num){
    vector<ll> v;
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

vector<pair<int, ll>> num_cnt;
int dfs(int idx, ll sum){
    if(idx == num_cnt.size()) return 1;

    ll num, cnt;
    tie(num, cnt) = num_cnt[idx];

    ll cur = 0, base = 1;
    for(int i=0; i<cnt+1; i++){
        cur += dfs(idx + 1, sum * base);
        base *= num;
        if(m < sum * base) break;
    }

    return cur;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>k>>m;

    auto v = prime_factorization(n);

    for(int i=0; i<v.size(); i++){
        int num = v[i];
        ll cnt = 0;
        while(i < v.size() && num == v[i]){
            i++;
            cnt++;
        }
        i--;
        num_cnt.emplace_back(num, cnt * k);
    }

    cout << dfs(0, 1) << endl;

    return 0;
}