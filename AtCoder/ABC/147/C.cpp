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
    vector<int> a(n);
    vector<vector<int>> x(n, vector<int>(20));
    vector<vector<int>> y(n, vector<int>(20));
    for(int i=0; i<n; i++){
        cin>>a[i];
        for(int j=0; j<a[i]; j++){
            cin>>x[i][j]>>y[i][j];
            x[i][j]--;
        }
    }

    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++){
        bool valid = true;
        set<int> honest;
        for(int i=0; i<n; i++){
            if(bit & (1 << i)) honest.emplace(i);
        }

        for(int i=0; i<n; i++){
            if(honest.count(i)){
                for(int j=0; j<a[i]; j++){
                    if(y[i][j] == 1 && !honest.count(x[i][j])) valid = false;
                    if(y[i][j] == 0 && honest.count(x[i][j])) valid = false;
                }
            }
        }

        if(valid) chmax(ans, (int)honest.size());
    }

    cout << ans << endl;

    return 0;
}