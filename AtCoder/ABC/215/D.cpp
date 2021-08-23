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

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    set<int> prime;
    for(int i=0; i<n; i++){
        int cur = a[i];
        for(int j=2; j*j<=a[i]; j++){
            while(cur % j == 0){
                cur /= j;
                prime.emplace(j);
            }
        }

        if(cur != 1){
            prime.emplace(cur);
        }
    }

    set<int> sub;
    for(auto i : prime){
        for(int j=i; j<=m; j+=i){
            sub.emplace(j);
        }
    }

    vector<int> ans;
    for(int i=1; i<=m; i++){
        if(!sub.count(i)) ans.emplace_back(i);
    }

    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i << endl;
    }

    return 0;
}