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

    string s; cin>>s;
    int n = s.size();

    int ans = 0;
    for(int len=1; len<n; len++){
        for(int i=2; i<n; i++){
            if(n <= i + 2 * len - 1) break;

            string s3 = s.substr(i, len);
            string s4 = s.substr(i + len, len);

            if(s3 != s4) continue;

            // [i, i + 2 * len - 1]
            string s2 = "", s6 = "";
            for(int j=1; j<n; j++){
                if(i - j - 1 < 0) break;
                if(n - j - 1 <= i + 2 * len - 1) break;
                s2 = s2 + s[i - j];
                s6 = s6 + s[n - j];

                ans += (s2 == s6);
            }
        }
    }

    cout << ans << endl;

    return 0;
}