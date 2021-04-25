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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; string s; cin>>n>>s;
    int q; cin>>q;
    int rev = 0;
    while(q--){
        int t, a, b; cin>>t>>a>>b;
        if(t == 1){
            a--, b--;
            if(rev == 1){
                a = (a + n) % (2 * n);
                b = (b + n) % (2 * n);
            }
            swap(s[a], s[b]);
        }
        else{
            rev ^= 1;
        }
    }

    string ans = s;
    if(rev) ans = s.substr(n) + s.substr(0, n);

    cout << ans << endl;

    return 0;
}