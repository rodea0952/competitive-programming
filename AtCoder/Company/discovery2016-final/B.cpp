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
    ll x; cin>>x;
    vector<int> t(n), a(n);
    for(int i=0; i<n; i++) cin>>t[i];
    for(int i=0; i<n; i++) cin>>a[i];

    int ng = 0, ok = 100001;
    while(ok - ng > 1){
        int mid = (ng + ok) / 2;

        vector<vector<int>> T(100010);
        for(int i=0; i<n; i++){
            T[min(t[i], mid)].emplace_back(a[i]);
        }

        ll sum = 0;
        priority_queue<int> pque;
        for(int i=mid; i>0; i--){
            for(auto j:T[i]) pque.emplace(j);
            if(pque.size()) sum += pque.top(), pque.pop();
        }

        if(x <= sum) ok = mid;
        else ng = mid;
    }

    cout << (ok == 100001 ? -1 : ok) << endl;

    return 0;
}