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
    string s; cin>>s;

    vector<set<int>> alp(26);
    for(int i=0; i<n; i++){
        alp[s[i] - 'a'].emplace(i);
    }

    int q; cin>>q;
    while(q--){
        int ty; cin>>ty;
        if(ty == 1){
            int i; cin>>i;
            char c; cin>>c;
            i--;
            for(int j=0; j<26; j++){
                if(alp[j].count(i)){
                    alp[j].erase(i);
                }
            }
            alp[c - 'a'].emplace(i);
        }
        else{
            int l, r; cin>>l>>r;
            l--, r--;
            int ans = 0;
            for(int i=0; i<26; i++){
                if(alp[i].empty()) continue;
                auto itr = alp[i].lower_bound(l);
                if(itr == alp[i].end()) continue;
                ans += (*itr <= r);
            }
            cout << ans << endl;
        }
    }

    return 0;
}