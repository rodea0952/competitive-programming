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

    int n; cin >> n;
    multiset<int> A, B, C;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        A.emplace(a);
    }
    for(int i=0; i<n; i++){
        int b; cin >> b;
        B.emplace(b);
    }
    for(int i=0; i<n; i++){
        int c; cin >> c;
        C.emplace(c);
    }

    int ans = 0;
    for(auto i : B){
        auto Aitr = A.lower_bound(i);
        if(Aitr == A.begin()) continue;
        auto Citr = C.upper_bound(i);
        if(Citr == C.end()) continue;
        Aitr--;
        ans++;
        A.erase(Aitr);
        C.erase(Citr);
    }

    cout << ans << endl;

    return 0;
}