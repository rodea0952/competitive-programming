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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin>>s;
    int n = s.size();
    deque<char> deq;
    for(int i=0; i<n; i++){
        deq.emplace_back(s[i]);
    }

    int q; cin>>q;
    bool rev = false;
    while(q--){
        int x; cin>>x;
        if(x == 1){
            if(!rev) rev = true;
            else rev = false;
        }
        else{
            int f; cin>>f;
            char c; cin>>c;
            if(f == 1){
                if(!rev) deq.emplace_front(c);
                else deq.emplace_back(c);
            }
            else{
                if(!rev) deq.emplace_back(c);
                else deq.emplace_front(c);
            }
        }
    }

    string ans = "";
    for(auto i : deq) ans += i;
    
    if(!rev){
        cout << ans << endl;
    }
    else{
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}