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

vector<int> makeTable(string &s){
    int n = s.size();
    vector<int> ret(n+1);
    ret[0] = -1;
    int j = -1;
    for(int i=0; i<n; i++){
        while(j >= 0 && s[i] != s[j]) j = ret[j];
        ret[i+1] = ++j;
    }

    return ret;
}

vector<int> kmp(string &str, string &word){
    vector<int> table = makeTable(word), ret;
    int m = 0, i = 0, n = str.size();
    while(m + i < n){
        if(word[i] == str[m+i]){
            if(++i == (int)(word.size())){ 
                ret.emplace_back(m);
                m += i - table[i];
                i = table[i];
            }
        }
        else{
            m += i - table[i];
            if(i > 0) i = table[i];
        }
    }
    
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;
    int m = s.size();
    vector<vector<int>> indeg(m+1);
    for(int i=0; i<n; i++){
        string t; cin>>t;
        auto idx = kmp(s, t);
        for(auto j : idx){
            indeg[j + t.size()].emplace_back(j);
        }
    }

    vector<ll> dp(m+1, 0);
    dp[0] = 1;
    for(int i=1; i<=m; i++){
        for(auto j : indeg[i]){
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }

    cout << dp[m] << endl;

    return 0;
}