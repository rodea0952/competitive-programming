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
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    vector<P> ap(n), bp(n);
    for(int i=0; i<n; i++){
        ap[i] = P(a[i], i);
        bp[i] = P(b[i], i);
    }
    sort(ap.begin(), ap.end());
    sort(bp.begin(), bp.end());

    bool valid = true;
    for(int i=0; i<n; i++){
        if(ap[i].first > bp[i].first) valid = false;
    }

    vector<int> index(n);
    for(int i=0; i<n; i++){
        index[ap[i].second] = i;
    }

    vector<bool> used(n, false);
    int cycle_cnt = 0;
    for(int i=0; i<n; i++){
        int cur = i;
        bool cycle_in = false;
        while(!used[cur]){
            cycle_in = true;
            used[cur] = true;
            cur = bp[cur].second;
            cur = index[cur];
        }
        cycle_cnt += cycle_in;
    }

    if(cycle_cnt == 1){
        bool can_change = false;
        for(int i=0; i<n-1; i++){
            if(bp[i].first >= ap[i+1].first) can_change = true;
        }
        if(!can_change) valid = false;
    }

    cout << (valid ? "Yes" : "No") << endl;

    return 0;
}