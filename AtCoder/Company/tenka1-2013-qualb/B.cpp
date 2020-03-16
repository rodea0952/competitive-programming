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

    int q; cin>>q;
    ll l; cin>>l;
    stack<P> st;
    ll sum = 0;
    while(q--){
        string s; cin>>s;
        if(s == "Push"){
            int n, m; cin>>n>>m;
            // 要素 m が n 個
            st.emplace(m, n);
            sum += n;

            if(l < sum){
                cout << "FULL" << endl;
                return 0;
            }
        }
        else if(s == "Pop"){
            int n; cin>>n;
            while(n > 0 && st.size()){
                int num, cnt; tie(num, cnt) = st.top(); st.pop();
                if(n >= cnt){
                    n -= cnt;
                    sum -= cnt;
                }
                else{
                    cnt -= n;
                    sum -= n;
                    n = 0;
                    st.emplace(num, cnt);
                }
            }

            if(n && !st.size()){
                cout << "EMPTY" << endl;
                return 0;
            }
        }
        else if(s == "Top"){
            if(!st.size()){
                cout << "EMPTY" << endl;
                return 0;
            }

            cout << st.top().first << endl;
        }
        else{
            cout << sum << endl;
        }
    }

    cout << "SAFE" << endl;

    return 0;
}