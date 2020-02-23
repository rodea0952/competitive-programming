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

    int n, m, k; cin>>n>>m>>k;
    char op; cin>>op;
    vector<int> b(m), a(n);
    for(int i=0; i<m; i++) cin>>b[i];
    for(int i=0; i<n; i++) cin>>a[i];

    ll ans = 0;
    if(op == '+'){
        map<int, int> bMODk;
        for(int i=0; i<m; i++){
            bMODk[b[i] % k]++;
        }

        for(int i=0; i<n; i++){
            int aMODk = a[i] % k;
            ans += bMODk[(k - aMODk) % k];
        }
    }
    else{
        map<ll, ll> agcd, bgcd;
        for(int i=0; i<n; i++) agcd[__gcd(k, a[i])]++;
        for(int i=0; i<m; i++) bgcd[__gcd(k, b[i])]++;

        for(auto i : agcd){
            for(auto j : bgcd){
                if(i.first * j.first % k == 0){
                    ans += i.second * j.second;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}