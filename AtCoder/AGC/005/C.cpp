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
    vector<int> a(n);
    vector<int> cnt(n, 0);
    for(int i=0; i<n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }

    int amax = *max_element(a.begin(), a.end());

    bool valid = true;
    if(amax % 2){
        int half = amax / 2 + 1;
        for(int i=half; i<=amax; i++){
            if(2 <= cnt[i]) cnt[i] -= 2;
            else valid = false;
        }

        for(int i=1; i<=half; i++){
            if(0 < cnt[i]) valid = false;
        }
    }
    else{
        int half = amax / 2;
        if(1 <= cnt[half]) cnt[half]--;
        else valid = false;

        for(int i=half+1; i<=amax; i++){
            if(2 <= cnt[i]) cnt[i] -= 2;
            else valid = false;
        }

        for(int i=1; i<=half; i++){
            if(0 < cnt[i]) valid = false;
        }
    }

    if(valid) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}