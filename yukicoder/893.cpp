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
    vector<vector<int>> a(n, vector<int>(110, -1));
    for(int i=0; i<n; i++){
        int p; cin>>p;
        for(int j=0; j<p; j++){
            cin>>a[i][j];
        }
    }

    vector<int> ans;
    for(int i=0; i<=100; i++){
        for(int j=0; j<n; j++){
            if(a[j][i] == -1) continue;
            ans.emplace_back(a[j][i]);
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " \n"[i == ans.size()-1];
    }

    return 0;
}