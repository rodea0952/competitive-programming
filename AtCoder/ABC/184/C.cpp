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

    int r1, c1, r2, c2; cin>>r1>>c1>>r2>>c2;

    int dr = abs(r2 - r1), dc = abs(c2 - c1);

    if(dr == 0 && dc == 0){
        cout << 0 << endl;
    }
    else if(dr == dc || dr + dc <= 3){
        cout << 1 << endl;
    }
    else if((dr + dc) % 2 == 0 || abs(dr - dc) <= 3 || dr + dc <= 6){
        cout << 2 << endl;
    }
    else{
        cout << 3 << endl;
    }

    return 0;
}