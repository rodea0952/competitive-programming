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

    string x; cin >> x;
    vector<int> pos(26);
    for(int i=0; i<26; i++){
        pos[x[i] - 'a'] = i;
    }

    int n; cin >> n;
    vector<string> s(n);
    for(int i=0; i<n; i++) cin >> s[i];

    sort(s.begin(), s.end(), [&](const string &a, const string &b){
        int len = min(a.size(), b.size());
        for(int i=0; i<len; i++){
            if(a[i] != b[i]){
                return pos[a[i] - 'a'] < pos[b[i] - 'a'];
            }
        }
        return a.size() < b.size();
    });

    for(auto ans : s){
        cout << ans << endl;
    }

    return 0;
}