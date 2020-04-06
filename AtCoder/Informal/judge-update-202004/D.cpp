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

    int n, q; cin>>n>>q;
    vector<int> a(n), s(q);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<q; i++) cin>>s[i];

    for(int i=1; i<n; i++){
        a[i] = __gcd(a[i], a[i-1]);
    }

    for(int i=0; i<q; i++){
        int ok = -1, ng = n;
        // (ok, ng]
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;

            if(__gcd(s[i], a[mid]) != 1) ok = mid;
            else ng = mid;
        }

        if(ng == n){
            cout << __gcd(a[n-1], s[i]) << endl;
        }
        else{
            cout << ng + 1 << endl;
        }
    }

    return 0;
}
