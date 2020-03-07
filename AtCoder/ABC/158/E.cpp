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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, p; cin>>n>>p;
    string s; cin>>s;

    ll ans = 0;
    if(p == 2 || p == 5){
        for(int i=0; i<n; i++){
            if((s[i] - '0') % p == 0) ans += (i + 1);
        }
    }
    else{
        reverse(s.begin(), s.end());
        ll base = 1, cur = 0;
        vector<ll> mod(n);
        for(int i=0; i<n; i++){
            mod[i] = ((s[i] - '0') * base + cur) % p;
            cur = mod[i];
            base *= 10;
            base %= p;
        }

        vector<ll> cnt(p, 0);
        cnt[0]++;
        for(auto i:mod) cnt[i]++;

        for(int i=0; i<p; i++){
            ans += cnt[i] * (cnt[i] - 1) / 2;
        }
    }

    cout << ans << endl;

    return 0;
}
