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

    ll n, k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];

    vector<int> pre(200010, -1);
    for(int i=n-1; i>=0; i--){
        pre[a[i]] = i;
    }

    vector<int> nxt;
    for(int i=n-1; i>=0; i--){
        nxt.emplace_back(pre[a[i]]);
        pre[a[i]] = i;
    }

    reverse(nxt.begin(), nxt.end());

    int id = 0;
    int period = 1;
    while(1){
        int nid = nxt[id];
        if(nid <= id) period++;
        id = (nid + 1) % n;
        if(id == 0) break;
    }

    k %= period;
    
    id = 0;
    period = 1;
    while(period < k){
        int nid = nxt[id];
        if(nid <= id) period++;
        id = (nid + 1) % n;
    }

    vector<int> ans;
    set<int> st;
    while(id < n){
        if(ans.size() && st.size() && st.find(a[id]) != st.end()){
            while(1){
                int val = ans.back();
                ans.pop_back();
                st.erase(val);
                if(val == a[id]) break;
            }
        }
        else{
            ans.emplace_back(a[id]);
            st.emplace(a[id]);
        }

        id++;
    }

    int m = ans.size();
    for(int i=0; i<m; i++){
        cout << ans[i] << " \n"[i == m-1];
    }
}