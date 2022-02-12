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

    int n = 1 << 20;
    vector<ll> a(n, -1);
    set<int> unused;
    for(int i=0; i<n; i++){
        unused.emplace(i);
    }

    int q; cin >> q;
    while(q--){
        int t; ll x; cin >> t >> x;
        if(t == 1){
            int h = x % n;
            if(a[h] == -1){
                a[h] = x;
                unused.erase(h);
            }
            else{
                auto itr = unused.upper_bound(h);
                int idx = -1;
                if(itr == unused.end()){
                    idx = *unused.begin();
                }
                else{
                    idx = *itr;
                }

                a[idx] = x;
                unused.erase(idx);
            }
        }
        else{
            cout << a[x % n] << endl;
        }
    }
}