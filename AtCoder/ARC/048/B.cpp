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

    int n; cin>>n;
    vector<vector<int>> rh(100001, vector<int>(4, 0));
    vector<int> r(n), h(n);
    vector<int> sort_r(n);
    for(int i=0; i<n; i++){
        cin>>r[i]>>h[i];
        sort_r[i] = r[i];
        rh[r[i]][h[i]]++;
    }

    sort(sort_r.begin(), sort_r.end());

    for(int i=0; i<n; i++){
        rh[r[i]][h[i]]--;

        int win = lower_bound(sort_r.begin(), sort_r.end(), r[i]) - sort_r.begin();
        int draw;
        if(h[i] == 1){
            win += rh[r[i]][2];
            draw = rh[r[i]][1];
        }
        else if(h[i] == 2){
            win += rh[r[i]][3];
            draw = rh[r[i]][2];
        }
        else{
            win += rh[r[i]][1];
            draw = rh[r[i]][3];
        }

        int lose = n - 1 - win - draw;

        cout << win << " " << lose << " " << draw << endl;

        rh[r[i]][h[i]]++;
    }

    return 0;
}