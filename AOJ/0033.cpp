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
    while(n--){
        vector<int> a(10);
        for(int i=0; i<10; i++) cin>>a[i];

        string ans = "NO";
        for(int bit=0; bit<(1<<10); bit++){
            vector<int> l, r;
            for(int i=0; i<10; i++){
                if(bit & (1 << i)) l.emplace_back(a[i]);
                else r.emplace_back(a[i]);
            }

            bool valid = true;
            for(int i=0; i+1<l.size(); i++){
                if(l[i] > l[i+1]) valid = false;
            }
            for(int i=0; i+1<r.size(); i++){
                if(r[i] > r[i+1]) valid = false;
            }

            if(valid) ans = "YES";
        }

        cout << ans << endl;
    }

    return 0;
}