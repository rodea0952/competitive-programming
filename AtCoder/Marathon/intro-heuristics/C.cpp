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

    int d; cin >> d;
    vector<int> c(26);
    vector<vector<int>> s(d, vector<int>(26));
    vector<int> t(d);
    for(int i=0; i<26; i++) cin >> c[i];
    for(int i=0; i<d; i++){
        for(int j=0; j<26; j++) cin >> s[i][j];
    }
    for(int i=0; i<d; i++) cin >> t[i], t[i]--;

    int score = 0;
    vector<set<int>> lst(26);
    for(int i=0; i<26; i++){
        lst[i].emplace(-1);
        lst[i].emplace(d);
    }
    for(int i=0; i<d; i++){
        score += s[i][t[i]];
        lst[t[i]].emplace(i);
        for(int j=0; j<26; j++){
            auto itr = lst[j].upper_bound(i);
            score -= c[j] * (i - *prev(itr));
        }
    }

    int m; cin >> m;
    while(m--){
        int d, q; cin >> d >> q; d--, q--;

        {
            score -= s[d][t[d]];
            auto itr = lst[t[d]].lower_bound(d);
            int gap1 = d - *prev(itr);
            int gap2 = *next(itr) - d;
            int gap3 = *next(itr) - *prev(itr);
            score += c[t[d]] * gap1 * (gap1 - 1) / 2;
            score += c[t[d]] * gap2 * (gap2 - 1) / 2;
            score -= c[t[d]] * gap3 * (gap3 - 1) / 2;
            lst[t[d]].erase(d);
        }

        {
            lst[q].emplace(d);
            score += s[d][q];
            auto itr = lst[q].lower_bound(d);
            int gap1 = d - *prev(itr);
            int gap2 = *next(itr) - d;
            int gap3 = *next(itr) - *prev(itr);
            score -= c[q] * gap1 * (gap1 - 1) / 2;
            score -= c[q] * gap2 * (gap2 - 1) / 2;
            score += c[q] * gap3 * (gap3 - 1) / 2;
        }
        
        t[d] = q;

        cout << score << endl;
    }

    return 0;
}