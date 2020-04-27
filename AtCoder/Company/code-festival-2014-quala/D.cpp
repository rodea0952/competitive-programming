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

    string a; cin>>a;
    int n = a.size();
    int K; cin>>K;

    ll ans = INF;
    for(int i=0; i<n; i++){
        for(char j='0'; j<='9'; j++){
            for(char k='0'; k<='9'; k++){
                string cur = a.substr(0, i) + j + string(n - 1 - i, k);
                
                while(cur.size() >= 2 && cur[0] == '0'){
                    cur = cur.substr(1);
                }

                set<char> st;
                for(auto l:cur) st.emplace(l);

                if(st.size() <= K){
                    chmin(ans, abs(stoll(a) - stoll(cur)));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}