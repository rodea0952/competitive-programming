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

    int h, w, k; cin>>h>>w>>k;
    vector<string> s(h);
    for(int i=0; i<h; i++) cin>>s[i];

    int ans = inf;
    for(int bit=0; bit<(1<<(h-1)); bit++){
        int row = __builtin_popcount(bit) + 1;
        int sum = row - 1;
        bool valid = true;
        vector<int> psum(row, 0);
        for(int j=0; j<w; j++){
            vector<int> ccost(row, 0);
            int idx = 0;
            for(int i=0; i<h; i++){
                if(s[i][j] == '1') ccost[idx]++;
                if(ccost[idx] > k) valid = false;
                if(bit & (1 << i)) idx++;
            }

            bool cut = false;
            for(int i=0; i<row; i++){
                if(psum[i] + ccost[i] > k) cut = true;
            }

            if(cut){
                sum++;
                for(int i=0; i<row; i++) psum[i] = ccost[i];
            }
            else{
                for(int i=0; i<row; i++) psum[i] += ccost[i];
            }
        }

        if(valid) chmin(ans, sum);
    }

    cout << ans << endl;

    return 0;
}