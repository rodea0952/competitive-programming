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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int cx, cy; cin>>cx>>cy;
    cx--, cy--;
    string s; cin>>s;
    vector<string> c(9);
    for(int i=0; i<9; i++) cin>>c[i];

    int dx = 0, dy = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'R') dx = 1;
        else if(s[i] == 'L') dx = -1;
        else if(s[i] == 'U') dy = -1;
        else dy = 1;
    }

    string ans;
    for(int i=0; i<4; i++){
        ans += c[cy][cx];

        int ny = cy + dy;
        if(8 < ny) dy = -1;
        if(ny < 0) dy = 1;

        int nx = cx + dx;
        if(8 < nx) dx = -1;
        if(nx < 0) dx = 1;

        cy += dy, cx += dx;
    }

    cout << ans << endl;

    return 0;
}