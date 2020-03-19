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

    string s;
    getline(cin, s);

    int n = s.size();
    set<string> ans;
    for(int i=0; i<n; i++){
        if(i + 1 < n && s[i] == '@' && 'a' <= s[i+1] && s[i+1] <= 'z'){
            string cur;
            for(int j=i+1; j<n; j++){
                if(s[j] == ' ' || s[j] == '@') break;
                cur += s[j];
            }
            ans.emplace(cur);
        }
    }

    for(auto i : ans) cout << i << endl;

    return 0;
}