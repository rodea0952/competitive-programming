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
    vector<int> s(n);
    for(int i=0; i<n; i++) cin>>s[i];

    ll ans = 0;
    // C = A - B
    for(int C=1; C<=n-1; C++){
        ll max_score = 0;
        ll score = 0;
        if((n - 1) % C == 0){
            int i = 0, j = n - 1;
            for(; i < j; i += C, j -= C){
                score += s[i] + s[j];
                chmax(max_score, score);
            }
        }
        else{
            int i = 0, j = n - 1;
            for(; i < n - 1 && C < j; i += C, j -= C){
                score += s[i] + s[j];
                chmax(max_score, score); 
            }
        }

        chmax(ans, max_score);
    }

    cout << ans << endl;

    return 0;
}