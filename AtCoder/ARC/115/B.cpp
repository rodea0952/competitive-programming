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

    int n; cin>>n;
    int c[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>c[i][j];
    }

    bool valid = true;
    int mi = inf, idx = -1;
    for(int i=0; i<n; i++){
        set<int> gap;
        if(c[i][0] <= mi){
            mi = c[i][0];
            idx = i;
        }
        for(int j=0; j<n; j++){
            gap.emplace(c[i][j] - c[(i + 1) % n][j]);
        }
        if(gap.size() != 1) valid = false;
    }

    if(!valid){
        cout << "No" << endl;
        return 0;
    }

    vector<int> b(n);
    for(int j=0; j<n; j++) b[j] = c[idx][j];

    vector<int> a(n);
    for(int i=0; i<n; i++) a[i] = c[i][0] - b[0];

    cout << "Yes" << endl;
    for(int i=0; i<n; i++){
        cout << a[i] << " \n"[i == n-1];
    }
    for(int i=0; i<n; i++){
        cout << b[i] << " \n"[i == n-1];
    }

    return 0;
}