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

    int n, m; cin>>n>>m;
    string s, t; cin>>s>>t;

    vector<int> cnts(26, 0), cntt(26, 0);
    for(int i=0; i<n; i++) cnts[s[i] - 'A']++;
    for(int i=0; i<m; i++) cntt[t[i] - 'A']++;

    int ans = 0;
    for(int i=0; i<26; i++){
        if(cnts[i]){
            if(!cntt[i]){
                cout << -1 << endl;
                return 0;
            }
            else{
                int need = (cnts[i] + cntt[i] - 1) / cntt[i];
                chmax(ans, need);
            }
        }
    }

    cout << ans << endl;

    return 0;
}