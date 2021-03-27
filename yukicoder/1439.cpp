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
    string s, t; cin>>s>>t;
    set<int> diff;
    for(int i=0; i<n; i++) if(s[i] != t[i]) diff.emplace(i);
    int q; cin>>q;
    while(q--){
        char c; cin>>c;
        int x; cin>>x; x--;
        char y; cin>>y;
        if(c == 'S') s[x] = y;
        else t[x] = y;

        if(s[x] == t[x]) diff.erase(x);
        else diff.emplace(x);

        if(diff.empty()){
            cout << "=" << endl;
            continue;
        }

        int idx = *diff.begin();
        if(s[idx] > t[idx]) cout << ">" << endl;
        else cout << "<" << endl;
    }

    return 0;
}