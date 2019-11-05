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
using P = pair<ll, ll>;
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

    int q; cin>>q;
    while(q--){
        ll n, k; cin>>n>>k;
        string s; cin>>s;
        vector<P> cnt1id0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') cnt++;
            else cnt1id0.emplace_back(cnt, i);
        }

        string ans = s;
        for(int i=0; i<cnt1id0.size(); i++){
            int cnt1, id;
            tie(cnt1, id) = cnt1id0[i];

            if(k - cnt1 >= 0){
                int lmove = id - cnt1;
                swap(ans[lmove], ans[id]);
            }
            else{
                int rest = max(0LL, k);
                int lmove = id - rest;
                swap(ans[lmove], ans[id]);
            }
            k -= cnt1;
        }

        cout << ans << endl;
    }

    return 0;
}