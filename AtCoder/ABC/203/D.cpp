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

vector<vector<int>> accumulation2D(vector<vector<int>> &v){
    int h = v.size(), w = v[0].size();
    vector<vector<int>> sum(h + 1, vector<int>(w + 1, 0));

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            sum[i + 1][j + 1] = sum[i + 1][j] + v[i][j];
        }
    }

    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            sum[j + 1][i + 1] += sum[j][i + 1];
        }
    }

    return sum;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    auto check = [&](int x) -> bool {
        bool valid = false;
        vector<vector<int>> cur(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(x < a[i][j]) cur[i][j] = 1;
            }
        }

        auto sum2D = accumulation2D(cur);
        for(int i=k; i<=n; i++){
            for(int j=k; j<=n; j++){
                int csum = sum2D[i][j] - sum2D[i - k][j] - sum2D[i][j - k] + sum2D[i - k][j - k];
                if(csum < k * k / 2 + 1) valid = true;
            }
        }

        return valid;
    };

    int ng = -1, ok = 1e9;
    while(ok - ng > 1){
        int mid = (ng + ok) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    cout << ok << endl;

    return 0;
}