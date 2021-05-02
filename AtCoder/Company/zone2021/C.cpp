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
    vector<vector<int>> a(n, vector<int>(5));
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++) cin>>a[i][j];
    }

    auto check = [&](int x) -> bool {
        set<int> st;
        for(int i=0; i<n; i++){
            int bit = 0;
            for(int j=0; j<5; j++){
                if(x <= a[i][j]) bit |= (1 << j);
            }
            st.emplace(bit);
        }

        bool valid = false;
        for(auto i : st){
            for(auto j : st){
                for(auto k : st){
                    if((i | j | k) == (1 << 5) - 1) valid = true;
                }
            }
        }

        return valid;
    };

    int ok = 1, ng = inf + 1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    cout << ok << endl;

    return 0;
}