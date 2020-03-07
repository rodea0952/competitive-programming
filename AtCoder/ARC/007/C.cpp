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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin>>s;
    int n = s.size();

    int ans = inf;
    for(int bit=0; bit<(1<<n); bit++){
        if(!(bit & 1)) continue;

        vector<string> t;
        for(int i=0; i<n; i++){
            if(bit & (1 << i)){
                string cur = string(i, 'x');
                for(int j=0; j<2*n; j++) cur += s;
                t.emplace_back(cur);
            }
        }

        int len = n * n * 2;
        bool fvalid = true;
        for(int i=n*n; i<len; i++){
            bool valid = false;
            for(int j=0; j<t.size(); j++){
                if(t[j][i] == 'o') valid = true;
            }
            if(!valid) fvalid = false;
        }

        if(fvalid){
            int sum = __builtin_popcount(bit);
            chmin(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}