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

    int same = 0;
    for(int i=0; i<=n/2-1; i++){
        if(s[i] == s[n-1-i]) same++;
    }

    int ans = n * 25;
    for(int i=0; i<=n/2-1; i++){
        for(int j=0; j<26; j++){
            int tmp_same = same;
            if(s[i] == s[n-1-i]) tmp_same--;

            char cur = 'A' + j;
            if(s[i] == cur) continue;

            if(cur == s[n-1-i]) tmp_same++;
            if(tmp_same == n / 2) ans -= 2;
        }
    }

    if(n % 2){
        if(same == n / 2) ans -= 25;
    }

    cout << ans << endl;

    return 0;
}