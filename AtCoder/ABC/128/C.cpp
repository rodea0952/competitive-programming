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

    int n, m; cin>>n>>m;
    vector<vector<int>> s(m);
    for(int i=0; i<m; i++){
        int k; cin>>k;
        for(int j=0; j<k; j++){
            int S; cin>>S;
            S--;
            s[i].emplace_back(S);
        }
    }

    vector<int> p(m);
    for(int i=0; i<m; i++) cin>>p[i];

    int ans = 0;
    for(int bit=0; bit<(1<<n); bit++){
        bool valid = true;
        for(int i=0; i<m; i++){
            int sum = 0;
            for(int j=0; j<s[i].size(); j++){
                if(bit & (1 << s[i][j])) sum++;
            }
            if(sum % 2 != p[i]) valid = false;
        }

        if(valid) ans++;
    }

    cout << ans << endl;

    return 0;
}