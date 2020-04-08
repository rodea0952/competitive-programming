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

    int n, k, c; cin>>n>>k>>c;
    string s; cin>>s;

    int cnt = 0;
    map<int, int> day;
    for(int i=0; i<n; i++){
        if(s[i] == 'o'){
            cnt++;
            day[i]++;
            i += c;
        }

        if(k < cnt){
            return 0;
        }
    }

    reverse(all(s));
    cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'o'){
            cnt++;
            day[n-i-1]++;
            i += c;
        }

        if(k < cnt){
            return 0;
        }
    }

    for(auto i:day){
        if(i.second == 2) cout << i.first + 1 << endl;
    }

    return 0;
}
