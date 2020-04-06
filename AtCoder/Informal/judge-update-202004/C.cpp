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

    vector<int> a(3);
    for(int i=0; i<3; i++) cin>>a[i];
    int n = a[0] + a[1] + a[2];

    vector<int> v(n, 0);
    iota(all(v), 0);

    int ans = 0;
    do{
        vector<vector<int>> A(5, vector<int>(5, inf));
        int cnt = 0;
        for(int i=0; i<3; i++){
            for(int j=0; j<a[i]; j++){
                if(cnt < n) A[i][j] = v[cnt++];
            }
        }

        bool valid = true;
        for(int i=0; i<3; i++){
            for(int j=0; j<4; j++){
                if(!(A[i][j] <= A[i][j+1])) valid = false;
            }
        }

        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(!(A[i][j] <= A[i+1][j])) valid = false;
            }
        }

        if(valid) ans++;

    }while(next_permutation(all(v)));

    cout << ans << endl;

    return 0;
}
