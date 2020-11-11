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

const int MAX_N = 100010;

bool isPrime[MAX_N];
void eratosthenes(int n){
    for(int i=0; i<=n; i++) isPrime[i] = true;
    isPrime[0] = false, isPrime[1] = false;

    for(int i=2; i*i<=n; i++){
        if(isPrime[i]){
            for(int j=2; i*j<=n; j++){
                isPrime[i*j] = false;
            }
        }
    }
}

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

    int n, k; cin>>n>>k;

    auto np = prime_factorization(n);
    map<int, int> npcnt;
    for(auto i:np){
        npcnt[i]++;
    }

    int ma = 0;
    int ans = 0;
    for(int m=1; m<n; m++){
        auto mp = prime_factorization(m);
        map<int, int> mpcnt;
        for(auto i:mp){
            mpcnt[i]++;
        }

        int cnt = 0, div = 1;
        for(auto i:mpcnt){
            cnt += min(i.second, npcnt[i.first]);
            div *= i.second + 1;
        }

        if(k <= cnt){
            if(ma < div){
                ma = div;
                ans = m;
            }
        }
    }

    cout << ans << endl;

    return 0;
}