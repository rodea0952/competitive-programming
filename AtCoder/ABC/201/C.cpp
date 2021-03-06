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

    string s; cin>>s;

    int ans = 0;
    for(int i=0; i<=9999; i++){
        vector<bool> exist(10, false);
        int cur = i;
        for(int j=0; j<4; j++){
            exist[cur % 10] = true;
            cur /= 10;
        }

        bool valid = true;
        for(int j=0; j<10; j++){
            if(s[j] == 'o' && !exist[j]) valid = false;
            if(s[j] == 'x' && exist[j]) valid = false;
        }
        ans += valid;
    }

    cout << ans << endl;

    return 0;
}