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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    ll asum = accumulate(a.begin(), a.end(), 0LL);

    bool valid = true;
    if(asum % (n * (n + 1) / 2) != 0) valid = false;

    ll k = asum / (n * (n + 1) / 2);

    vector<int> d(n);
    for(int i=0; i<n; i++){
        d[i] = a[i] - a[(i-1+n)%n];
        d[i] -= k;
    }

    ll cnt = 0;
    for(int i=0; i<n; i++){
        if(0 < d[i]){
            valid = false;
        }
        else{
            if(d[i] % n != 0){
                valid = false;
            }
            else{
                cnt += (- d[i] / n);
            }
        }
    }

    if(cnt != k) valid = false;

    cout << (valid ? "YES" : "NO") << endl;

    return 0;
}