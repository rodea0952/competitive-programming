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

    int a, b; cin>>a>>b;

    vector<int> ans;
    ll asum = 0, bsum = 0;
    if(a >= b){
        for(int i=0; i<a; i++){
            ans.emplace_back(i + 1);
            asum += i + 1;
        }
        for(int i=0; i<b-1; i++){
            ans.emplace_back(-(i + 1));
            asum -= i + 1;
        }
        ans.emplace_back(-asum);
    }
    else{
        for(int i=0; i<a-1; i++){
            ans.emplace_back(i + 1);
            bsum += i + 1;
        }
        for(int i=0; i<b; i++){
            ans.emplace_back(-(i + 1));
            bsum += -(i + 1);
        }
        ans.emplace_back(-bsum);
    }

    for(int i=0; i<a+b; i++){
        cout << ans[i] << " \n"[i == a+b-1];
    }

    return 0;
}