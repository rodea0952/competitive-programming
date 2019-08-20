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

    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i]>>b[i];

    set<int> divisor;
    for(int i=1; i*i<=a[0]; i++){
        if(a[0] % i == 0){
            divisor.emplace(i);
            divisor.emplace(a[0] / i);
        }
    }
    
    for(int i=1; i*i<=b[0]; i++){
        if(b[0] % i == 0){
            divisor.emplace(i);
            divisor.emplace(b[0] / i);
        }
    }

    int ans;
    for(auto i : divisor){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(a[j] % i == 0 || b[j] % i == 0) cnt++;
        }

        if(cnt == n) ans = i;
    }

    cout << ans << endl;
}