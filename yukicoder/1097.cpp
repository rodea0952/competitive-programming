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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    vector<bool> visited(n, false);
    vector<ll> pre_step(n+1, 0);
    int cv = 0, pre_sum = 0;
    while(!visited[cv]){
        visited[cv] = true;
        pre_sum++;
        pre_step[pre_sum] = pre_step[pre_sum - 1] + a[cv];
        cv = (cv + a[cv]) % n;
    }

    for(int i=0; i<n; i++) visited[i] = false;
    vector<ll> loop_step(n+1, 0);
    int loop_sum = 0;
    while(!visited[cv]){
        visited[cv] = true;
        loop_sum++;
        loop_step[loop_sum] = loop_step[loop_sum - 1] + a[cv];
        cv = (cv + a[cv]) % n;
    }

    int q; cin>>q;
    while(q--){
        ll k; cin>>k;
        ll ans;

        if(k <= pre_sum){
            ans = pre_step[k];
        }
        else{
            ans = pre_step[pre_sum];
            k -= pre_sum;
            ans += loop_step[loop_sum] * (k / loop_sum) + loop_step[k % loop_sum];
        }

        cout << ans << endl;
    }

    return 0;
}