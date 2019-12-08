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
    vector<string> w(n);
    for(int i=0; i<n; i++) cin>>w[i];

    vector<string> ans;
    for(int i=0; i<n; i++){
        string t;
        int sz = w[i].size();
        for(int j=0; j<sz; j++){
            char cur = w[i][j];
            if(cur == 'b' || cur == 'c' || cur == 'B' || cur == 'C') t += '1';
            if(cur == 'd' || cur == 'w' || cur == 'D' || cur == 'W') t += '2';
            if(cur == 't' || cur == 'j' || cur == 'T' || cur == 'J') t += '3';
            if(cur == 'f' || cur == 'q' || cur == 'F' || cur == 'Q') t += '4';
            if(cur == 'l' || cur == 'v' || cur == 'L' || cur == 'V') t += '5';
            if(cur == 's' || cur == 'x' || cur == 'S' || cur == 'X') t += '6';
            if(cur == 'p' || cur == 'm' || cur == 'P' || cur == 'M') t += '7';
            if(cur == 'h' || cur == 'k' || cur == 'H' || cur == 'K') t += '8';
            if(cur == 'n' || cur == 'g' || cur == 'N' || cur == 'G') t += '9';
            if(cur == 'z' || cur == 'r' || cur == 'Z' || cur == 'R') t += '0';
        }

        if(t.size() != 0) ans.emplace_back(t);
    }

    if(ans.size() == 0){
        cout << endl;
    }
    else{
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
    }

    return 0;
}