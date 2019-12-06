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
    string s, t; cin>>s>>t;

    set<char> used;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isdigit(s[j]) || isdigit(t[j])){
                if(isdigit(s[j])) used.emplace(t[j]);
                else used.emplace(s[j]);
            }
            else if(used.count(s[j]) || used.count(t[j])){
                if(used.count(s[j])) used.emplace(t[j]);
                else used.emplace(s[j]); 
            }
        }
    }

    ll ans = 1;
    for(int i=0; i<n; i++){
        if(!(used.count(s[i]) || used.count(t[i]))){
            if(i == 0) ans *= 9;
            else ans *= 10;
        }

        used.emplace(s[i]);
        used.emplace(t[i]);
    }

    cout << ans << endl;

    return 0;
}