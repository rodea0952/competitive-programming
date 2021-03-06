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

    string x; cin>>x;
    ll m; cin>>m;
    int d = *max_element(all(x)) - '0';

    if(x.size() == 1){
        cout << (d <= m) << endl;
        return 0;
    }

    auto f = [&](ll n) -> bool {
        ll sum = 0;
        for(int i=0; i<x.size(); i++){
            if(sum > m / n) return false;
            sum *= n;
            sum += x[i] - '0';
        }
        return (sum <= m ? true : false);
    };

    ll ok = d, ng = m + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok - d << endl;

    return 0;
}