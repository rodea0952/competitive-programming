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

    string s, t; cin>>s>>t;
    
    if(t.size() == 1){
        for(int i=0; i<s.size(); i++){
            if(s[i] == t[0]){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    auto head = kmp(s, t);

    int cur = 0, ans = 0;
    for(int i=0; i<head.size(); i++){
        if(cur <= head[i]){
            cur = head[i] + t.size() - 1;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}