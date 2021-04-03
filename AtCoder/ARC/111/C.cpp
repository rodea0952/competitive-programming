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
    vector<int> a(n), b(n), p(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    for(int i=0; i<n; i++) cin>>p[i], p[i]--;

    bool valid = true;
    for(int i=0; i<n; i++){
        if(i != p[i] && a[i] <= b[p[i]]) valid = false;
    }

    if(!valid){
        cout << -1 << endl;
        return 0;
    }

    vector<P> ai(n);
    for(int i=0; i<n; i++) ai[i] = P(a[i], i);
    sort(all(ai));

    vector<int> q(n);
    for(int i=0; i<n; i++) q[p[i]] = i;

    vector<P> ans;
    for(int i=0; i<n; i++){
        int weight, idx; tie(weight, idx) = ai[i];
        if(idx == p[idx]) continue;

        ans.emplace_back(idx, q[idx]);
        q[p[idx]] = q[idx];
        swap(p[idx], p[q[idx]]);
    }

    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i.first + 1 << " " << i.second + 1 << endl;
    }

    return 0;
}