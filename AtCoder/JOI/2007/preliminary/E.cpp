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

    int a, b, c; cin>>a>>b>>c;
    int n; cin>>n;
    vector<vector<int>> abc(n, vector<int>(3));
    vector<int> r(n);
    vector<int> ans(a+b+c+1, 2);
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) cin>>abc[i][j];
        cin>>r[i];
        if(r[i] == 1){
            for(int j=0; j<3; j++){
                ans[abc[i][j]] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(r[i] == 0){
            int cnt1 = 0;
            for(int j=0; j<3; j++){
                if(ans[abc[i][j]] == 1) cnt1++;
            }

            if(cnt1 == 2){
                for(int j=0; j<3; j++){
                    if(ans[abc[i][j]] == 2){
                        ans[abc[i][j]] = 0;
                    }
                }
            }
        }
    }

    for(int i=1; i<=a+b+c; i++){
        cout << ans[i] << endl;
    }

    return 0;
}