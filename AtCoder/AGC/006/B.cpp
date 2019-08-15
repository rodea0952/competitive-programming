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

    int n, x; cin>>n>>x;
    if(x == 1 || x == 2 * n - 1){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    vector<int> v;
    for(int i=1; i<=2*n-1; i++){
        if(i == x - 1 || i == x || i == x + 1) continue;
        v.emplace_back(i);
    }

    for(int i=0; i<n-2; i++){
        cout << v[i] << endl;
    }
    for(int i=x-1; i<=x+1; i++){
        cout << i << endl;
    }
    for(int i=n-2; i<2*n-4; i++){
        cout << v[i] << endl;
    }
}