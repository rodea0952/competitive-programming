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

vector<int> v;

void rec(ll num){
    if(1e9 <= num) return ;

    v.emplace_back(num);

    rec(num * 10 + 3);
    rec(num * 10 + 5);
    rec(num * 10 + 7);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;

    rec(0);

    set<int> num357;
    for(auto i:v){
        bool is3 = false;
        bool is5 = false;
        bool is7 = false;

        int num = i;
        while(0 < num){
            if(num % 10 == 3) is3 = true;
            if(num % 10 == 5) is5 = true;
            if(num % 10 == 7) is7 = true;
            num /= 10;
        }

        if(is3 && is5 && is7) num357.emplace(i);
    }

    int ans = 0;
    for(auto i:num357){
        if(n < i) break;
        ans++;
    }

    cout << ans << endl;
}