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

    string s2 = s;
    while(s2.size() < t.size()) s2 += s;
    s = s2;

    int n = s.size(), m = t.size();
    s += s;

    auto v = kmp(s, t);

    vector<bool> sindex(n, false);
    for(auto i : v){
        sindex[i % n] = true; 
    }

    int ans = 0;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(!sindex[i] || visited[i]) continue;

        visited[i] = true;
        int sum = 1;

        int nxt = i;
        while(1){
            nxt = (nxt + m) % n;
            if(nxt == i){
                cout << -1 << endl;
                return 0;
            }
            else if(sindex[nxt] && !visited[nxt]){
                sum++;
                visited[nxt] = true;
            }
            else{
                break;
            }
        }

        int pre = i;
        while(1){
            pre = (pre - m + (int)s.size()) % n;
            if(pre == i){
                cout << -1 << endl;
                return 0;
            }
            else if(sindex[pre] && !visited[pre]){
                sum++;
                visited[pre] = true;
            }
            else{
                break;
            }
        }

        chmax(ans, sum);
    }

    cout << ans << endl;
}